#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <list>
#include "BaseTest.h"

namespace st
{

class TestSuite: public BaseTest, public std::list<BaseTest*>
{
public:
    TestSuite(const std::string& description);
    ~TestSuite();

private:
    
};

}

#endif // TESTSUITE_H