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
    int binarySearch(vector<int>& numbers, int target, int beginIndex, int endIndex) {
        while (beginIndex <= endIndex) {
            int midIndex = (beginIndex + endIndex) / 2;
            int midValue = numbers[midIndex];
            if (midValue == target) {
                return midIndex;
            } else if (target < midValue) {
                endIndex = midIndex - 1;
            } else if (target > midValue) {
                beginIndex = midIndex + 1;
            }
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int endIndex = numbers.size() - 1;

        vector<int> result(2);
        for (int i = 0; i < endIndex; i++) {
            int targetIndex = binarySearch(numbers, target - numbers[i], i + 1, endIndex);
            if (targetIndex > 0) {
                result[0] = i + 1;
                result[1] = targetIndex + 1;
                break;
            }
        }
        return result;
    }

    vector<int> twoSum2(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                break;
        }
        return vector<int>{left + 1, right + 1};
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {2,7,11,15};
    // int target = 9;
    // vector<int> nums = {2,3,4};
    // int target = 6;
    vector<int> nums = {-1,0};
    int target = -1;
    vector<int> result = s.twoSum2(nums, target);
    printf("resut: [%d, %d]\n", result[0], result[1]);
    return 0;
}