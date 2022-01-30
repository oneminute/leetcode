#include <iostream>
#include <string>
#include <vector>
#include <SimpleTest.h>

using namespace std;
 
// 判断字符是否符合要求
bool isMatchStar(char c)
{
    return (isalpha(c)||isalnum(c)||c=='.');
}
 
bool Match(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();

    int i = 0;
    int j = 0;

    bool match = true;
    while (i < m || j < n)
    {
        if (s1[i] == '*')
        {
            if (isMatchStar(s2[j]))
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        else if (s1[i] == '?')
        {
            if (isMatchStar(s2[j]))
            {
                i++;
                j++;
            }
            else
            {
                // 不匹配
                match = false;
                break;
            }
        }
        else
        {
            if (tolower(s1[i]) == tolower(s2[j]))
            {
                i++;
                j++;
            }
            else
            {
                match = false;
                break;
            }
        }
        if (j == n)
        {
            if (!(i == (m - 1) && s1[i] == '*'))
            {
                match = false;
            }
            break;
        }
        if (i == n)
        {
            if (j != n)
            {
                match = false;
            }
            break;
        }
    }

    return match;
}
int main(void)
{
    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    // suite.push_back(new st::StreamTestCase("Test 01", "aa\na", "false"));
    suite.push_back(new st::StreamTestCase("Test 02", "*\naa", "true"));
    suite.push_back(new st::StreamTestCase("Test 03", "?a\ncb", "false"));
    suite.push_back(new st::StreamTestCase("Test 04", "*a*b\nadceb", "true"));
    suite.push_back(new st::StreamTestCase("Test 05", "?a\ncb", "false"));
    runner.addTask(&suite);
    runner.start();


    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(Match(s1, s2)){
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
        runner.check();
    }

    runner.finish();
    return 0;
}
