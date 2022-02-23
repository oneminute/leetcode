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
    suite.push_back(new st::StreamTestCase("Test 01", "8 8 8  8A i i OOI              IIIaa", "3"));
    runner.addTask(&suite);
    runner.start();

    int total = 0;
    string line;
    getline(cin, line);
    
    char target;
    cin >> target;
    target = tolower(target);
    
    for (int i = 0; i < line.length(); i++)
    {
        char c = tolower(line[i]);
        
        if (c == target)
            total++;
    }
    
    cout << total << endl;
    
    runner.check();
    runner.finish();
    return 0;
}