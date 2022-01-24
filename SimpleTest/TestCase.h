#ifndef TESTCASE_H
#define TESTCASE_H

#include "BaseTest.h"
#include <sstream>

namespace st
{

class TestCase: public BaseTest
{
public:
    TestCase(const std::string& description, const char* testData, const std::string& expect);
    TestCase(const std::string& description, const std::string& filename, const std::string& expect);
    ~TestCase();

    std::streambuf* testDataBuf() { return m_testDataBuf; };

    virtual bool launch() override;

    bool check(const std::string& actual);

private:
    std::streambuf* m_testDataBuf;
    std::string m_expect;
};

}
#endif