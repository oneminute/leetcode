#ifndef STREAMTESTRUNNER_H
#define STREAMTESTRUNNER_H

#include <iostream>
#include <list>
#include <queue>
#include "BaseTest.h"
#include "BaseRunner.h"

namespace st
{

class StreamTestCase;

class StreamTestRunner : public BaseRunner, public std::streambuf
{
public:
    using TaskList = std::list<BaseTest*>;
    using TaskListIterator = TaskList::iterator;
    using TaskListConstIterator = TaskList::const_iterator;
    using TaskQueue = std::queue<StreamTestCase*>;

    StreamTestRunner(unsigned long long bufferSize = 1024 * 1024 * 2);
    ~StreamTestRunner();

    void addTask(BaseTest* task);
    void removeTask(BaseTest* task);
    virtual void start();
    virtual void finish();
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
    char m_currChar;
    std::vector<std::streambuf::char_type> m_buffer;
};

}
#endif // STREAMTESTRUNNER_H
