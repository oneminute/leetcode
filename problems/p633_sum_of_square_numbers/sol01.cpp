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
    bool judgeSquareSum(int c) {
        // method 1
        // for (long long i = 0; i <= sqrt((c + 1) / 2); i++) {
        //     long long n1 = i * i;
        //     long long n2 = c - n1;
        //     if (n2 < 0)
        //         break;
        //     long long j = round(sqrt(n2));
        //     if (n2 == j * j)
        //         return true;
        // }
        // return false;

        // method 2
        long long i = 0;
        long long j = (long) sqrt(c);

        while (i <= j) {
            long long sum = i * i + j * j;
            if (sum < c)
                i++;
            else if (sum > c)
                j--;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        int c = 5;
        printf("result: %d\n", sol.judgeSquareSum(c));
    }
    {
        int c = 3;
        printf("result: %d\n", sol.judgeSquareSum(c));
    }
    {
        int c = 6;
        printf("result: %d\n", sol.judgeSquareSum(c));
    }
    {
        int c = 0;
        printf("result: %d\n", sol.judgeSquareSum(c));
    }
    return 0;
}