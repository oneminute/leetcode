/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    int findKthLargest2(vector<int>& nums, int k) {
        size_t l = 0;
        size_t r = nums.size() - 1;
        size_t target = nums.size() - k;
        while (l < r) {
            size_t i = l + 1, j = r;
            while (true) {
                while (j > l && nums[j] >= nums[l])
                    j--;
                while (i < r && nums[i] <= nums[l])
                    i++;
                if (i >= j)
                    break;
                swap(nums[j], nums[i]);
            }
            swap(nums[l], nums[j]);

            if (target == j)
                return nums[j];
            if (j >= target)
                r = j - 1;
            else
                l = j + 1;

        }
        return nums[l];
    }

    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> numsSet;
        vector<int> numsVec;
        for (int n: nums) {
            numsSet.insert(n);
        }
        numsVec.assign(numsSet.begin(), numsSet.end());

        return numsVec[numsVec.size() - k];
    }

    int findKthLargest3(vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        const int N = nums.size();
        for (int i = 0; i < N; ++i) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {7,6,5,4,3,2,1};
        int k = 5;
        cout << s.findKthLargest(nums, k) << endl;
    }
    {
        vector<int> nums = {1};
        int k = 1;
        cout << s.findKthLargest(nums, k) << endl;
    }
    {
        vector<int> nums = {1};
        int k = 1;
        cout << s.findKthLargest(nums, k) << endl;
    }
    {
        vector<int> nums = {3,3,3,3,4,3,3,3,3};
        int k = 1;
        cout << s.findKthLargest(nums, k) << endl;
    }
    {
        vector<int> nums = {3,2,1,5,6,4};
        int k = 2;
        cout << s.findKthLargest(nums, k) << endl;
    }
    {
        vector<int> nums = {3,2,3,1,2,4,5,5,6};
        int k = 4;
        cout << s.findKthLargest(nums, k) << endl;
    }
    
    printf("\n");
    return 0;
}