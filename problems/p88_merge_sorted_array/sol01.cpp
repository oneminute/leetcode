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

        int i = nums1.size() - 1;
        while (i1 >= 0 && i2 >= 0) {
            nums1[i--] = nums1[i1] > nums2[i2] ? nums1[i1--] : nums2[i2--];
        }
        while (i2 >= 0) {
            nums1[i--] = nums2[i2--];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    // vector<int> nums1 = {1};
    // int m = 1;
    // vector<int> nums2 = {};
    // int n = 0;
    // vector<int> nums1 = {0};
    // int m = 0;
    // vector<int> nums2 = {1};
    // int n = 1;
    s.merge(nums1, m, nums2, n);
    printf("[");
    for (int i = 0; i < nums1.size(); i++) {
        printf("%d, ", nums1[i]);
    }
    printf("]\n");
    return 0;
}