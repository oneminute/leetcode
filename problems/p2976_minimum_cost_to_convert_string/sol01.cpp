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
    int minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_multimap<int, int> 
    }
};

int main()
{
    Solution s;
    string source1 = "abcd", target1 = "acbe";
    vector<char> original1 = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed1 = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost1 = {2, 5, 5, 1, 2, 20};
    
    string source2 = "aaaa", target2 = "bbbb";
    vector<char> original2 = {'a', 'c'};
    vector<char> changed2 = {'c', 'b'};
    vector<int> cost2 = {1, 2};
    
    string source3 = "abcd", target3 = "abce";
    vector<char> original3 = {'a'};
    vector<char> changed3 = {'e'};
    vector<int> cost3 = {10000};
    
    cout << "Minimum cost for example 1: " << s.minimumCost(source1, target1, original1, changed1, cost1) << endl;
    cout << "Minimum cost for example 2: " << s.minimumCost(source2, target2, original2, changed2, cost2) << endl;
    cout << "Minimum cost for example 3: " << s.minimumCost(source3, target3, original3, changed3, cost3) << endl;

    return 0;
}