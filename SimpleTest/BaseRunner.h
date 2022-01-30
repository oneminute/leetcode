#ifndef BASERUNNER_H
#define BASERUNNER_H

#include <chrono>

namespace st
{
class BaseRunner
{
public:
    using DurationMS = std::chrono::milliseconds;
    using TimeStamp = std::chrono::time_point<std::chrono::steady_clock>;

    BaseRunner()
        : m_passed(0)
        , m_failed(0)
        , m_started(false)
    {}
    ~BaseRunner()
    {}

    virtual void start();
    virtual void finish();
    bool isStarted() const { return m_started; }

    int passed() const { return m_passed; }
    int failed() const { return m_failed; }

    void addPassed() { m_passed++; }
    void addfailed() { m_failed++; }

protected:
    void setStarted(bool started = true) { m_started = started; }

private:
    int m_passed;
    int m_failed;
    DurationMS m_duration;
    TimeStamp m_startTime;
    bool m_started;
};
}

#endif // BASERUNNER_H
