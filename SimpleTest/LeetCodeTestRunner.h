#ifndef LEETCODETESTRUNNER_H
#define LEETCODETESTRUNNER_H

#include <list>
#include "BaseRunner.h"
#include "LeetCodeTestCase.h"
#include "TestSuite.h"

// #ifdef NO_TEST
//     #define BEGIN_TEST_RUNNER
//     #define END_TEST_RUNNER
//     #define BEGIN_TEST_RUNNER(Solution, FnName)
//     #define BEGIN_LEETCODE_TEST_CASE(caseName, desc, T, expect)
//     #define END_LEETCODE_TEST_CASE(caseName)
//     #define END_TEST_RUNNER
// #else
//     #define BEGIN_TEST_RUNNER() \
//     int main() \
//     { \
//         st::LeetCodeTestRunner runner;

//     #define LEETCODE_TEST_CASE(caseName, funcName, desc, T, expect) \
//     st::LeetCodeTestCase<T> caseName(std::string(desc), expect, [=] () { \
//         Solution<T> sol; \
//         return sol.funcName
//     ;});

//     #define END_TEST_RUNNER \
//         return 0; \
//     }
// #endif

namespace st
{

template<typename T>
class LeetCodeTestRunner: public BaseRunner
{
public:
    LeetCodeTestRunner()
    {}

    ~LeetCodeTestRunner()
    {}

    void addTask(BaseTest* task)
    {
        m_tasks.push_back(task);
    }

    virtual void start()
    {
        BaseRunner::start();
        for (BaseTest* task: m_tasks)
        {
            TestSuite* suite = dynamic_cast<TestSuite*>(task);
            if (suite)
            {
                for (std::list<BaseTest*>::iterator i = suite->begin(); i != suite->end(); i++)
                {
                    check(*i);
                }
            }
            check(task);
        }
    }

    virtual void finish()
    {
        BaseRunner::finish();
    }

protected:
    void check(BaseTest* task)
    {
        LeetCodeTestCase<T>* t = dynamic_cast<LeetCodeTestCase<T>*>(task);
        if (!t)
            return;
        t->start();
        if (t->check())
        {
            std::cout << "[st] " << t->description() << ": Passed." << std::endl;
            addPassed();
        }
        else
        {
            std::cerr << "[st] " << t->description() << ": failed." << std::endl;
            addfailed();
        }
        t->finish(&std::cout);
    }

private:
    std::list<BaseTest*> m_tasks;
};
}

#endif // LEETCODETESTRUNNER_H
