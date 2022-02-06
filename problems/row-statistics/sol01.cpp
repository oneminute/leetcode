#include <vector>
#include <iostream>
#include <string>
#include <SimpleTest.h>

using namespace std;

int main(int argc, char *argv[])
{

    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("Test 01", "-- variable a\nint a = 0;\n-- variable b\nint b = 1; string str1 =\n \"with;--\"; char c = ';';", "6"));
    runner.addTask(&suite);
    runner.start();

    string lineData;
    int lineCount = 0;

    while (std::getline(cin, lineData))
    {
        int i = 0;
        if (lineData[0] == '-' && lineData[1] == '-')   // 通过判断前两个字符是否为--，来确定该行是否为注释行
        {
            i = lineData.find('\n');    // 直接找回车符，若找到则该注释行结束，否则可能已经到文档结尾
            lineCount++;
            i++;
            if (i == string::npos)
                break;
        }

        for (; i < lineData.size(); i++)
        {
            if (lineData[i] == '\"')    // 找到左引号后，直接找右括号，前提是引号不跨行。如果引号跨行，不能这么判断
            {
                i = lineData.find('\"', i);
            }
            else if (lineData[i] == '\'')
            {
                i = lineData.find('\"', i);
            }
            else if (lineData[i] == ';')
            {
                lineCount++;
            }
        }
    }
    cout << lineCount << endl;
    runner.check();
    runner.finish();

    return 0;
}