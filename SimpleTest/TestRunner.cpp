#include "TestRunner.h"

#include <stack>

#include "TestCase.h"
#include "TestSuite.h"

namespace st
{

TestRunner::TestRunner(unsigned long long bufferSize)
    : std::streambuf()
    , m_started(false)
    , m_coutStream(nullptr)
{
    m_buffer = std::vector<char>(bufferSize, 0);
    setp(m_buffer.data(), m_buffer.data() + bufferSize);
}

TestRunner::~TestRunner()
{

}

void TestRunner::addTask(BaseTest* task)
{
    m_tasks.push_back(task);
}

void TestRunner::removeTask(BaseTest* task)
{
    auto it = std::find(m_tasks.begin(), m_tasks.end(), task);
    m_tasks.erase(it);
    delete task;
}

void TestRunner::start()
{
    m_cinBuf = std::cin.rdbuf(this);
    m_coutBuf = std::cout.rdbuf(this);
    m_coutStream = new std::ostream(m_coutBuf);
    initTaskQueue();
    m_result = std::string();
}

void TestRunner::finish()
{
    if (!m_started)
        return;
    std::cout << std::endl;
    std::cin.rdbuf(m_cinBuf);
    std::cout.rdbuf(m_coutBuf);
    delete m_coutStream;
    std::cout << "[st] Finished" << std::endl;
    m_started = false;
}

void TestRunner::check()
{
    if (m_assertionQueue.empty())
        return;

    sync();
    TestCase* task = m_assertionQueue.front();
    m_assertionQueue.pop();

    if (task->check(m_result))
    {
        *m_coutStream << "[st] " << task->description() << ": Passed" << std::endl;
    }
    else
    {
        std::cerr << "[st] " << task->description() << ": Failure (expect: " << task->expect() << ", actual: " << m_result << ")" << std::endl;
    }
    m_result = std::string();
}

std::streambuf::int_type TestRunner::underflow()
{
    if (!m_started)
    {
        // throw std::exception("Test runner has not been started.");
        std::cerr << "[st] Test runner has not been started." << std::endl;
        return traits_type::eof();
    }

    if (m_taskQueue.empty())
        return traits_type::eof();

    std::streambuf* currBuf = m_taskQueue.front()->testDataBuf();

    // Read one character and move the current buffer advance.
    std::streambuf::int_type i = currBuf->sbumpc();

    // if it reaches to the end of current buffer, move forward to next buffer
    if (traits_type::eq_int_type(i, traits_type::eof())) 
    {
        m_taskQueue.pop();
        if (m_taskQueue.empty())
            return traits_type::eof();
        else
        {   // before moving to next buffer, we should return a '\n' character to end current line
            i = '\n';
            m_currChar = traits_type::to_char_type(i);
            setg(&m_currChar, &m_currChar, &m_currChar + 1);
            return i;
        }
    }

    m_currChar = traits_type::to_char_type(i);
    setg(&m_currChar, &m_currChar, &m_currChar + 1);
    return i;
}

std::streambuf::int_type TestRunner::overflow(std::streambuf::int_type value)
{
    if (!m_started)
    {
        // throw std::exception("Test runner has not been started.");
        std::cerr << "[st] Test runner has not been started." << std::endl;
        return traits_type::eof();
    }

    setp(m_buffer.data(), m_buffer.data() + m_buffer.size());
    return traits_type::not_eof(value);
}

std::streambuf::int_type TestRunner::sync()
{
    long long writeSize = pptr() - pbase();

    if (writeSize)
    {
        char tail = *(pptr() - 1);
        if (tail == '\n')
            writeSize--;
        if (writeSize)
        {
            m_result.append(std::string(pbase(), writeSize));
            *m_coutStream << m_result << std::endl;
        }
    }

    return overflow(traits_type::eof());
}

void TestRunner::initTaskQueue()
{
    if (m_tasks.empty())
        return;

    m_taskQueue = TaskQueue();
    m_assertionQueue = TaskQueue();
    
    for (BaseTest* i: m_tasks)
    {
        TestSuite* suite = dynamic_cast<TestSuite*>(i);
        if (suite)
        {
            for(BaseTest* c: *suite)
            {
                TestCase* caseItem = dynamic_cast<TestCase*>(c);
                if (caseItem)
                {
                    m_taskQueue.push(caseItem);
                    m_assertionQueue.push(caseItem);
                }
            }
        }
        else
        {
            TestCase* caseItem = dynamic_cast<TestCase*>(i);
            m_taskQueue.push(caseItem);
            m_assertionQueue.push(caseItem);
        }
    }
    m_started = true;
}

}