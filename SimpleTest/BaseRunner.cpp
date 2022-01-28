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
    int total = passed() + failure();
    std::cout << "[st] SimpleTest finished. " << passed() << "/" << total << " passed, " << failure() << "/" << total << " failure" << std::endl;
    setStarted(false);
}

}
