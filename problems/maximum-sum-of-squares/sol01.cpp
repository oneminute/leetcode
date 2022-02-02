/**
 * 
 * @file sol01.cpp
 * @author 毒舌大叔
 * @brief 
 * 
 * @version 0.1
 * @date 2022-02-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <SimpleTest.h>

using namespace std;

// 判断字符串是否符合要求
inline int convert(const std::string& str)
{
    if (str[0] == 0)
        return 0;
    else
    {
        int value = std::stoi(str);
        return value;
    }
}
 
int main(void)
{
    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("test01", "fffdddds(3,4)aaaaddd(2,3)sdfghjk(5,10)fifid(01,4)dwdff(0,0)diwdi(100,0)dwidfh", "(5,10)"));
    runner.addTask(&suite);
    runner.start();

    string data;
    while(cin >> data)
    {
        int maxSum = 0;
        int maxX = 0, maxY = 0;
        int begin = -1;
        int comma = -1;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '(')
            {
                begin = i;
            }
            else if (data[i] == ',')
            {
                if (begin > -1)
                    comma = i;
            }
            else if (data[i] == ')')
            {
                std::string strX = data.substr(begin + 1, comma - begin - 1);
                std::string strY = data.substr(comma + 1, i - comma - 1);
                int x = convert(strX);
                int y = convert(strY);
                if (x && y)
                {
                    int sum = x * x + y * y;
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                        maxX = x;
                        maxY = y;
                    }
                }
                begin = -1;
                comma = -1;
            }
        }
        cout << "(" << maxX << "," << maxY << ")" << endl;
        runner.check();
    }

    runner.finish();
    return 0;
}