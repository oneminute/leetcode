#ifndef STREAMTESTCASE_H
#define STREAMTESTCASE_H

#include "BaseTest.h"
#include <sstream>
#include <functional>

namespace st
{

class StreamTestCase: public BaseTest
{
public:
    StreamTestCase(const std::string& description, const char* testData, const std::string& expect);
    StreamTestCase(const std::string& description, const std::string& filename, const std::string& expect);
    ~StreamTestCase();

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
#endif // STREAMTESTCASE_H