#include <vector>
#include <iostream>
#include <string>
#include <SimpleTest.h>

using namespace std;

inline int getDigit(string& str, int index)
{
    int rightIndex = str.length() - 1 - index;
    if (rightIndex >= 0)
        return str[rightIndex] - '0';
    else
        return 0;
}

int main(int argc, char *argv[])
{

    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("Test 01", "99765 765", "100530"));
    runner.addTask(&suite);
    runner.start();

    string s1, s2;

    while (cin >> s1 >> s2)
    {
        int carry = 0;
        int maxSize = max(s1.size(), s2.size());
        vector<int> final(maxSize + 1, 0);
        for (int i = 0; i < maxSize; i++)
        {
            int d1 = getDigit(s1, i);
            int d2 = getDigit(s2, i);
            int d = d1 + d2 + carry;
            carry = d / 10;
            d = d % 10;
            final[i] = d;
        }
        final[maxSize] += carry;

        if (final.back())
            cout << final.back();
        for (int i = final.size() - 2; i >= 0; i--)
        {
            cout << final[i];
        }
        cout << endl;

        runner.check();
    }
    runner.finish();

    return 0;
}
