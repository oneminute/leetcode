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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [=] (vector<int>& i1, vector<int>& i2) {
            if (i1[1] < i2[1]) {
                return true;
            } else if (i1[1] > i2[1]) {
                return false;
            } else {
                return (i1[0] > i2[0]);
            }
        });

        list<vector<int>> queue;
        queue.push_back(people[0]);
        for (int i = 1; i < people.size(); i++) {
            int height = people[i][0];
            int count = people[i][1];
            list<vector<int>>::iterator it = queue.begin();
            for (; it != queue.end(); it++) {
                if (height <= it->at(0)) {
                    count--;
                }
                if (count < 0)
                    break;
            }
            queue.insert(it, people[i]);
        }

        int i = 0;
        for (list<vector<int>>::iterator it = queue.begin(); it != queue.end(); it++) {
            people[i][0] = it->at(0);
            people[i][1] = it->at(1);
            i++;
        }

        return people;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    people = s.reconstructQueue(people);
    for (int i = 0; i < people.size(); i++) {
        printf("[%d, %d], ", people[i][0], people[i][1]);
    }
    printf("\n");
    return 0;
}