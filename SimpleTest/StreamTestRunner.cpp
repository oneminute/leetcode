#include "StreamTestRunner.h"

#include <stack>

#include "StreamTestCase.h"
#include "TestSuite.h"

namespace st
{

StreamTestRunner::StreamTestRunner(unsigned long long bufferSize)
    : std::streambuf()
    , m_coutStream(nullptr)
{
    m_buffer = std::vector<char>(bufferSize, 0);
    setp(m_buffer.data(), m_buffer.data() + bufferSize);
}

StreamTestRunner::~StreamTestRunner()
{

}

void StreamTestRunner::addTask(BaseTest* task)
{
    m_tasks.push_back(task);
}

void StreamTestRunner::removeTask(BaseTest* task)
{
    auto it = std::find(m_tasks.begin(), m_tasks.end(), task);
    m_tasks.erase(it);
    delete task;
}

void StreamTestRunner::start()
{
    BaseRunner::start();

    m_cinBuf = std::cin.rdbuf(this);
    m_coutBuf = std::cout.rdbuf(this);
    m_coutStream = new std::ostream(m_coutBuf);
    initTaskQueue();
    m_result = std::string();
}

void StreamTestRunner::finish()
{
    if (!isStarted())
        return;
    std::cout << std::endl;
    std::cin.rdbuf(m_cinBuf);
    std::cout.rdbuf(m_coutBuf);
    delete m_coutStream;
    std::cout << "[st] Finished" << std::endl;
    BaseRunner::finish();
}

void StreamTestRunner::check()
{
    if (m_assertionQueue.empty())
        return;

    sync();
    StreamTestCase* task = m_assertionQueue.front();
    m_assertionQueue.pop();

    if (task->check(m_result))
    { 
        addPassed();
        task->finish(m_coutStream);
    }
    else
    {
        addfailed();
        task->finish(m_coutStream, "(expect: " + task->expect() + ", actual: " + m_result + ")");
    }
    
    m_result = std::string();
}

std::streambuf::int_type StreamTestRunner::underflow()
{
    if (!isStarted())
    {
        std::cerr << "[st] Test runner has not been started." << std::endl;
        return traits_type::eof();
    }

    if (m_taskQueue.empty())
        return traits_type::eof();

    StreamTestCase* t = m_taskQueue.front();
    t->start();
    std::streambuf* currBuf = t->testDataBuf();

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

std::streambuf::int_type StreamTestRunner::overflow(std::streambuf::int_type value)
{
    if (!isStarted())
    {
        // throw std::exception("Test runner has not been started.");
        std::cerr << "[st] Test runner has not been started." << std::endl;
        return traits_type::eof();
    }

    setp(m_buffer.data(), m_buffer.data() + m_buffer.size());
    return traits_type::not_eof(value);
}

std::streambuf::int_type StreamTestRunner::sync()
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

void StreamTestRunner::initTaskQueue()
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
                StreamTestCase* caseItem = dynamic_cast<StreamTestCase*>(c);
                if (caseItem)
                {
                    m_taskQueue.push(caseItem);
                    m_assertionQueue.push(caseItem);
                }
            }
        }
        else
        {
            StreamTestCase* caseItem = dynamic_cast<StreamTestCase*>(i);
            m_taskQueue.push(caseItem);
            m_assertionQueue.push(caseItem);
        }
    }
}

}