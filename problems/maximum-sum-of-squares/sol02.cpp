/**
 * 
 * @file sol02.cpp
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
#include <regex>
#include <SimpleTest.h>

using namespace std;

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
        int comma = -1;
        std::regex pattern("\\(([1-9]{1,}[0-9]{0,},[1-9]{1,}[0-9]{0,})\\)");
        auto matchBegin = std::sregex_iterator(data.begin(), data.end(), pattern);
        auto matchEnd = std::sregex_iterator();
        for (std::sregex_iterator i = matchBegin; i != matchEnd; i++)
        {
            std::smatch match = *i;
            std::string matchStr = match.str();
            comma = matchStr.find(',');
            std::string strX = matchStr.substr(1, comma - 1);
            std::string strY = matchStr.substr(comma + 1, matchStr.size() - comma - 1);
            int x = stoi(strX);
            int y = stoi(strY);
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
        }
        cout << "(" << maxX << "," << maxY << ")" << endl;
        runner.check();
    }

    runner.finish();
    return 0;
}