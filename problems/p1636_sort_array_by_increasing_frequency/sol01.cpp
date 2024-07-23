/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <minmax.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int num: nums) {
            freqMap[num]++;
        }

        sort(nums.begin(), nums.end(), [&] (int a, int b) {
            if (freqMap[a] == freqMap[b]) {
                return a > b;
            }
            return freqMap[a] < freqMap[b];
        });
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {2, 3, 1, 3, 2};
    vector<int> nums3 = {-1, 1, -6, 4, 5, -6, 1, 4, 1};

    vector<int> sortedNums1 = s.frequencySort(nums1);
    vector<int> sortedNums2 = s.frequencySort(nums2);
    vector<int> sortedNums3 = s.frequencySort(nums3);

    for (int num : sortedNums1) cout << num << " ";
    cout << endl;

    for (int num : sortedNums2) cout << num << " ";
    cout << endl;

    for (int num : sortedNums3) cout << num << " ";
    cout << endl;

    return 0;
}