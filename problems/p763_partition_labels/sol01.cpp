/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <minmax.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitions;
        if (s.size() == 0)
            return partitions;
        int letters[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int* indices = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            indices[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (letters[index] >= 0) {
                indices[letters[index]] = i;
            }
            letters[index] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            printf("indices[%d] = %d\n", i, indices[i]);
        }
        int index = 0;
        int target = -1;
        int i = 0;
        int count = 0;
        while (i < s.length()) {
            if (indices[i] > 0) {
                if (indices[i] > target)
                    target = indices[i];
            }
            if (indices[i] > target) {
                target = indices[i];
            }
            if (i == target || target < 0) {
                count = max(1, target - index + 1);
                partitions.push_back(count);
                index = i + 1;
                target = -1;
            }
            i++;
        }
        delete[] indices;
        return partitions;
    }
};

int main()
{
    Solution s;
    // string str = "ababcbacadefegdehijhklij";
    // string str = "eccbbbbdec";
    string str = "eaaaabaaec";
    vector<int> partitions = s.partitionLabels(str);
    printf("[");
    for (int i = 0; i < partitions.size(); i++) {
        printf("%d, ", partitions[i]);
    }
    printf("]");
    return 0;
}