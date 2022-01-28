#ifndef BASETEST_H
#define BASETEST_H

#include <chrono>
#include <iostream>
#include <list>
#include <string>

namespace st
{

class BaseTest
{
public:
    using DurationMS = std::chrono::milliseconds;
    using TimeStamp = std::chrono::time_point<std::chrono::steady_clock>;

    BaseTest(const std::string& description)
        : m_description(description)
        , m_started(false)
    {}
    ~BaseTest()
    {}

    std::string description() const { return m_description; }

    virtual void start();
    virtual void finish(std::ostream* out, const std::string& reason = "");

protected:
    void setResult(bool passed) { m_result = passed; }
    bool result() const { return m_result; }

private:
    std::string m_description;
    bool m_result;
    DurationMS m_duration;
    TimeStamp m_startTime;
    bool m_started;
};

}

#endif