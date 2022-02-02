/**
 * @file sol01.cpp
 * @author your name (you@domain.com)
 * @brief 
 * reference from https://blog.csdn.net/zhaitianbao/article/details/120303885?utm_source=app&app_version=5.0.0&utm_source=app
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <SimpleTest.h>

using namespace std;
 
// 判断字符是否符合要求
bool isOk(char c)
{
    return (isalpha(c)||isalnum(c)||c=='.');
}
 
bool Match(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<bool>> v(m+1,vector<bool>(n+1,false));
    v[0][0] = true;
    for(int i=1;i<=m;++i)
    {
        v[i][0] = v[i-1][0]&&(s1[i-1]=='*');
        for(int j=1;j<=n;++j)
        {
            if(s1[i-1]=='*'){
                if(isOk(s2[j-1]))
                {
                    v[i][j] = v[i-1][j]||v[i][j-1];
                }
            }else{
                if(tolower(s1[i-1])==tolower(s2[j-1]))
                    v[i][j] = v[i-1][j-1];
                if(s1[i-1]=='?' && isOk(s2[j-1]))
                    v[i][j] = v[i-1][j-1];
            }
        }
    }
    return v[m][n];
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
