/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>

using namespace std;

int dp[320];
int totalMoney;
int number;

int main()
{
    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    // suite.push_back(new st::StreamTestCase("Test 01", "1000 5\n800 2 0\n400 5 1\n300 5 1\n400 3 0\n500 2 0", "2200"));
    suite.push_back(new st::StreamTestCase("Test 02", "50 5\n20 3 5\n20 3 5\n10 3 0\n10 2 0\n10 1 0", "130"));
    // suite.push_back(new st::StreamTestCase("Test 02", "1000 5\n300 5 0\n400 2 0\n300 5 2\n300 4 2\n600 4 0", "3900"));
    runner.addTask(&suite);
    runner.start();

    cin >> totalMoney >> number;
    // int* items = new int[6 * number]{0};
    int items[30] = {0};
    totalMoney /= 10;

    for (int i = 0; i < number; i++)
    {
        int price, weight, parent; 
        cin >> price >> weight >> parent;

        if (parent)
        {
            int parentIndex = (parent - 1) * 6;
            if (items[parentIndex + 2] == 0)
            {
                items[parentIndex + 2] = price / 10;
                items[parentIndex + 3] = price * weight;
            }
            else
            {
                items[parentIndex + 4] = price / 10;
                items[parentIndex + 5] = price * weight;
            }
        }
        else
        {
            items[i * 6] = price / 10;
            items[i * 6 + 1] = price * weight;
        }
    }

    for (int i = 0; i < number * 6; i += 6)
    {
        int price = items[i];
        int value = items[i + 1];
        int price1 = items[i + 2];
        int value1 = items[i + 3];
        int price2 = items[i + 4];
        int value2 = items[i + 5];

        if (!price)
            continue;

        for (int j = totalMoney; j >= (price - price1 - price2); j--)
        {
            if (j >= price)
                dp[j] = max(dp[j], dp[j - price] + value);
            if (j >= price + price1)
                dp[j] = max(dp[j], dp[j - price - price1] + value + value1);
            if (j >= price + price2)
                dp[j] = max(dp[j], dp[j - price - price2] + value + value2);
            if (j >= price + price1 + price2)
                dp[j] = max(dp[j], dp[j - price - price1 - price2] + value + value1 + value2);
        }
    }

    std::cout << dp[totalMoney] << endl;
    
    runner.check();
    runner.finish();
    return 0;
}