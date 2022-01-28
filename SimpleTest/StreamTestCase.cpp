#include "StreamTestCase.h"
#include <fstream>

namespace st
{

StreamTestCase::StreamTestCase(const std::string& description, const char* testData, const std::string& expect)
    : BaseTest(description)
    , m_testDataBuf(nullptr)
    , m_expect(expect)
{
    m_testDataBuf = new std::stringbuf(testData);
}

StreamTestCase::StreamTestCase(const std::string& description, const std::string& filename, const std::string& expect)
    : BaseTest(description)
    , m_testDataBuf(nullptr)
    , m_expect(expect)
{
    std::filebuf* fbuf = new std::filebuf;
    if (!fbuf->open(filename, std::ios::in))
    {
        std::cout << "open file failure: " << filename << std::endl;
        delete fbuf;
        fbuf = nullptr;
    }
    m_testDataBuf = fbuf;
}

StreamTestCase::~StreamTestCase()
{
    if (m_testDataBuf)
    {
        delete m_testDataBuf;
        m_testDataBuf = nullptr;
    }
}

bool StreamTestCase::check(const std::string& actual)
{
    return actual == m_expect;
}

}