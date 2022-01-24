#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <iostream>
#include <list>
#include <queue>
#include "BaseTest.h"

namespace st
{

class TestCase;

class TestRunner : public std::streambuf
{
public:
    using TaskList = std::list<BaseTest*>;
    using TaskListIterator = TaskList::iterator;
    using TaskListConstIterator = TaskList::const_iterator;
    using TaskQueue = std::queue<TestCase*>;

    TestRunner(unsigned long long bufferSize = 1024 * 1024 * 2);
    ~TestRunner();

    void addTask(BaseTest* task);
    void removeTask(BaseTest* task);
    void start();
    void finish();
    void check();

    virtual std::streambuf::int_type underflow();
    virtual std::streambuf::int_type overflow(std::streambuf::int_type value);
    virtual std::streambuf::int_type sync();

protected:
    void initTaskQueue();

private:
    std::list<BaseTest*> m_tasks;
    TaskQueue m_taskQueue;
    TaskQueue m_assertionQueue;
    std::streambuf* m_cinBuf;
    std::streambuf* m_coutBuf;
    std::ostream* m_coutStream;
    std::string m_result;
    bool m_started;
    char m_currChar;
    std::vector<std::streambuf::char_type> m_buffer;
};

}
#endif // TESTRUNNER_H
