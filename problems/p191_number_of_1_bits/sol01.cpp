/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingWeight3(int n) {
        int count = 0;
        while (n != 0) {
            if (n & 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }

    int hammingWeight2(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    int hammingWeight1(int n) {
        bitset<32> bn(n);
        return bn.count();
    }

    int hammingWeight(int n) {
        return hammingWeight3(n);
    }
};

int main()
{
    Solution s;
    {
        int result = s.hammingWeight(11);
        cout << result << endl;
    }
    
    cout << endl;
    return 0;
}