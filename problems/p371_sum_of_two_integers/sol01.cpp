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
    bool add(bool bita, bool bitb, bool& carry) {
        bool ret = bita ^ bitb;
        carry = bita & bitb;
        return ret;
    }

    int getSum1(int a, int b) {
        bitset<32> ba(a);
        bitset<32> bb(b);
        bitset<32> bc(0);
        bool carry = 0;
        for (int i = 0; i < 32; i++) {
            bool newCarry = false;
            bool res = add(ba[i], bb[i], newCarry);
            res = add(res, carry, carry);
            carry = carry || newCarry;
            if (res) bc.set(i);
        }

        return static_cast<int>(bc.to_ulong());
    }

    int getSum2(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }

    int getSum(int a, int b) {
        return getSum2(a, b);
    }
};

int main()
{
    Solution s;
    {
        int result = s.getSum(1, 2);
        cout << result << endl;
    }
    
    cout << endl;
    return 0;
}