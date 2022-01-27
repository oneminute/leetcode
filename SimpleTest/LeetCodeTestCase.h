#ifndef LEETCODETESTCASE_H
#define LEETCODETESTCASE_H

#include "BaseTest.h"
#include <sstream>
#include <functional>

namespace st
{

template<typename T>
class LeetCodeTestCase: public BaseTest
{
public:
    using TestFn = std::function<T()>;

    LeetCodeTestCase(const std::string& description, T expect, TestFn fn)
        : BaseTest(description)
        , m_fn(fn)
        , m_expect(expect)
    {}

    ~LeetCodeTestCase()
    {}

    virtual bool check()
    {
        return m_expect == m_fn();
    }

    const T& expect()
    {
        return m_expect;
    }

private:
    TestFn m_fn;
    T m_expect;
};

}
#endif //
