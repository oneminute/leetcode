#ifndef TESTCASE_H
#define TESTCASE_H

#include "BaseTest.h"
#include <sstream>
#include <functional>

namespace st
{

class TestCase: public BaseTest
{
public:
    TestCase(const std::string& description);
    TestCase(const std::string& description, const char* testData, const std::string& expect);
    TestCase(const std::string& description, const std::string& filename, const std::string& expect);
    ~TestCase();

    std::string expect() { return m_expect; }

    std::streambuf* testDataBuf() { return m_testDataBuf; };

    bool check(const std::string& actual);

    template<typename T>
    bool check(std::function<T()> fn)
    {
        return fn();
    }

private:
    std::streambuf* m_testDataBuf;
    std::string m_expect;
};

}
#endif