#include "TestSuite.h"
#include "TestCase.h"

namespace st
{

TestSuite::TestSuite(const std::string& description)
    : BaseTest(description)
    , std::list<TestCase*>()
{

}

TestSuite::~TestSuite()
{

}

bool TestSuite::launch()
{
    return true;
}

}