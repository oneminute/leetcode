#include "BaseTest.h"

namespace st
{

void BaseTest::start()
{
    if (m_started)
        return;
    m_startTime = std::chrono::steady_clock::now();
    m_started = true;
}

void BaseTest::finish(std::ostream* out, const std::string& reason)
{
    auto now = std::chrono::steady_clock::now();
    m_duration = std::chrono::duration_cast<DurationMS>(now - m_startTime);
    (*out) << "[st] " 
        << description() 
        << (result() ? " Passed" : " Failure")
        << " in "
        << m_duration.count()
        << " ms. "
        << reason
        << std::endl;
        m_started = false;
}

}
