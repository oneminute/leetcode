#include "BaseRunner.h"

#include <iostream>

namespace st
{

void BaseRunner::start()
{
    std::cout << "[st] SimpleTest started..." << std::endl;
    setStarted();
}

void BaseRunner::finish()
{
    int total = passed() + failed();
    std::cout << "[st] SimpleTest finished. " << passed() << "/" << total << " passed, " << failed() << "/" << total << " failed" << std::endl;
    setStarted(false);
}

}
