#include "TestSuite.h"
#include "StreamTestCase.h"

namespace st
{

TestSuite::TestSuite(const std::string& description)
    : BaseTest(description)
    , std::list<BaseTest*>()
{

}

TestSuite::~TestSuite()
{

}

}