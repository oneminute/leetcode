#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <list>
#include "BaseTest.h"

namespace st
{

class TestCase;
class TestSuite: public BaseTest, public std::list<TestCase*>
{
public:
    TestSuite(const std::string& description);
    ~TestSuite();

    virtual bool launch();

private:
    
};

}

#endif // TESTSUITE_H