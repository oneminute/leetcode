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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty())
            return 0;

        bool odd = ((nums1.size() + nums2.size()) & 1) == 1;
        int medianIndex = (nums1.size() + nums2.size()) >> 1;

        double n1 = 0, n2 = 0;
        int i1 = 0, i2 = 0;
        for (int i = 0; i <= medianIndex; i++) {
            int n = -1;
            if (i1 >= nums1.size()) {
                n = nums2[i2];
                i2++;
            } else if (i2 >= nums2.size()) {
                n = nums1[i1];
                i1++;
            } else if (nums1[i1] < nums2[i2]) {
                n = nums1[i1];
                i1++;
            } else {
                n = nums2[i2];
                i2++;
            }
            if (i == 0) {
                n1 = n;
            } else {
                n1 = n2;
            }
            n2 = n;
        }

        if (odd) {
            return n2;
        } else {
            return (n1 + n2) / 2;
        }
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums1 = {1,3};
        vector<int> nums2 = {2};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
    {
        vector<int> nums1 = {};
        vector<int> nums2 = {};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
    {
        vector<int> nums1 = {};
        vector<int> nums2 = {3,4};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
    {
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
    {
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3,4};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
    {
        vector<int> nums1 = {1,3};
        vector<int> nums2 = {2};
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
    
    printf("\n");
    return 0;
}