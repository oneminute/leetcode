#ifndef LEETCODETESTRUNNER_H
#define LEETCODETESTRUNNER_H

#include "LeetCodeTestCase.h"
#include "TestSuite.h"
#include <list>

// #ifdef NO_TEST
//     #define BEGIN_TEST_RUNNER
//     #define END_TEST_RUNNER
//     #define BEGIN_TEST_RUNNER(Solution, FnName)
//     #define BEGIN_LEETCODE_TEST_CASE(caseName, desc, T, expect)
//     #define END_LEETCODE_TEST_CASE(caseName)
//     #define END_TEST_RUNNER
// #else
//     #define BEGIN_TEST_RUNNER(Solution) \
//     int main() \
//     { \
//         Solution sol; \
//         st::LeetCodeTestRunner runner;

//     #define BEGIN_LEETCODE_TEST_CASE(caseName, desc, T, expect) \
//     st::LeetCodeTestCase<T> caseName(std::string(desc), expect, [=] () { \
//         return sol.

//     #define END_LEETCODE_TEST_CASE \
//     ;});

//     #define END_TEST_RUNNER \
//         return 0; \
//     }
// #endif

namespace st
{

class LeetCodeTestRunner
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

    void start()
    {
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

    void finish()
    {}

protected:
    void check(BaseTest* task)
    {
        if (task->check())
        {
            std::cout << "[st] " << task->description() << ": Passed." << std::endl;
        }
        else
        {
            std::cerr << "[st]" << task->description() << ": Failure." << std::endl;
        }
    }

private:
    std::list<BaseTest*> m_tasks;
};
}

#endif // LEETCODETESTRUNNER_H
