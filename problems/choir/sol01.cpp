/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>

using namespace std;

class Solution
{
public:
    int leastRemoval(int n, int* heights)
    {
        int* left = new int[n];
        int* right = new int[n];
        
        // i for left, j for right
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            left[i] = 1;
            for (int ii = 0; ii < i; ii++)
            {
                if (heights[i] > heights[ii])
                {
                    left[i] = max(left[i], left[ii] + 1);
                }
            }
            
            right[j] = 1;
            for (int jj = n - 1; jj > j; jj--)
            {
                if (heights[j] > heights[jj])
                {
                    right[j] = max(right[j], right[jj] + 1);
                }
            }
        }
        
        int minRemoval = n;
        for (int i = 0; i < n; i++)
        {
            int removal = n - left[i] - right[i] + 1;
            minRemoval = min(removal, minRemoval);
        }
        delete[] left;
        delete[] right;
        return minRemoval;
    }
};

int main()
{
    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("Test 01", "8\n186 186 150 200 160 130 197 200", "4"));
    runner.addTask(&suite);
    runner.start();

    Solution s;
    int n = 0;
    while (cin >> n)
    {
        int* heights = new int[n];
        for (int i = 0; i < n; i++)
            cin >> heights[i];
        cout << s.leastRemoval(n, heights);
        delete[] heights;
        runner.check();
    }
    runner.finish();
    return 0;
}