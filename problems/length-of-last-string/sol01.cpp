/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>

using namespace std;


int main()
{
    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("Test 01", "hello world", "5"));
    runner.addTask(&suite);
    runner.start();

    string str;
    while (cin >> str);
    cout << str.length() << endl;
    
    runner.check();
    runner.finish();
    return 0;
}