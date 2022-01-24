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
    BaseTest(const std::string& description)
        : m_description(description)
    {}
    ~BaseTest()
    {}

    std::string description() { return m_description; }

    virtual bool launch() = 0;

private:
    std::string m_description;
};

}

#endif