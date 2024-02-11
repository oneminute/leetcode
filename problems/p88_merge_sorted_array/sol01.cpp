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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            int n; 
            if (i2 < 0 || nums1[i1] >= nums2[i2]) {
                n = nums1[i1];
                i1--;
            } else if (i1 < 0 || nums1[i1] < nums2[i2]) {
                n = nums2[i2];
                i2--;
            }
            nums1[i] = n;
        }
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {2,7,11,15};
    // int target = 9;
    // vector<int> nums = {2,3,4};
    // int target = 6;
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    s.merge(nums1, m, nums2, n);
    printf("[");
    for (int i = 0; i < nums1.size(); i++) {
        printf("%d, ", nums1[i]);
    }
    printf("]\n");
    return 0;
}