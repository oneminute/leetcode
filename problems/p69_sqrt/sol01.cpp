/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        int l = 1, r = x, m, sqrt;
        while (l <= r) {
            m = l + (r - l) / 2;
            sqrt = x / m;
            if (sqrt == m) {
                break;
            } else if (sqrt < m) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return sqrt;
    }

    int mySqrt2(int x) {
        long a = x;
        while (a * a > x) {
            a = (a + x / a) / 2;
        }
        return a;
    }
};

int main()
{
    Solution s;
    {
        int x = 4;
        cout << "sqrt(" << x << ") = " << s.mySqrt(x) << endl;
        cout << "sqrt(" << x << ") = " << s.mySqrt2(x) << endl;
    }
    {
        int x = 8;
        cout << "sqrt(" << x << ") = " << s.mySqrt(x) << endl;
        cout << "sqrt(" << x << ") = " << s.mySqrt2(x) << endl;
    }
    {
        int x = 32;
        cout << "sqrt(" << x << ") = " << s.mySqrt(x) << endl;
        cout << "sqrt(" << x << ") = " << s.mySqrt2(x) << endl;
    }
    printf("\n");
    return 0;
}