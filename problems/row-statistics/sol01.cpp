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
    bool commentLine = false;

    while (cin >> lineData)
    {
        int i = 0;
        if (lineData[0] == '-' && lineData[1] == '-')   // 通过判断前两个字符是否为--，来确定该行是否为注释行
        {
            commentLine = true;
            i = lineData.find('\n');    // 直接找回车符，若找到则该注释行结束，否则可能已经到文档结尾
            lineCount++;
            i++;
            if (i == string::npos)
                break;
        }

        bool quotaBegin = false;
        char beginChar;
        for (; i < lineData.size(); i++)
        {
            if (quotaBegin)    // 首先判断是否已经有左引号了，如果已经有左引号了，除右引号、分号和回外外其它字符均无视
            {
                if (lineData[i] == '\"' && beginChar == '\"')
                {
                    quotaBegin = false;
                }
                if (lineData[i] == '\'' && beginChar == '\'')
                {
                    quotaBegin = false;
                }
            }
            else if (lineData[i] == '\"')
            {
                quotaBegin = true;
                beginChar = '\"';
            }
            else if (lineData[i] == '\'')
            {
                quotaBegin = true;
                beginChar = '\'';
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