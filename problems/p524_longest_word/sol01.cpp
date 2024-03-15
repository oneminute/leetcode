/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:

    bool matchString(string& s, string& word) {
        bool matched = false;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == word[j]) {
                j++;
            }
        }
        return j >= word.length();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string target = "";
        size_t strLen = 0;

        for (string& word : dictionary) {
            if (matchString(s, word)) {
                if (word.length() > strLen) {
                    target = word;
                    strLen = word.length();
                } else if (word.length() == strLen) {
                    if (word < target) {
                        target = word;
                    }
                }
            }
        }

        return target;
    }
};

int main()
{
    {
        Solution sol;
        string s = "abpcplea";
        vector<string> dictionary = {"ale","apple","monkey","plea"};
        string output = sol.findLongestWord(s, dictionary);
        printf("result: %s\n", output.c_str());
    }
    {
        Solution sol;
        string s = "abpcplea";
        vector<string> dictionary = {"a","b","c"};
        string output = sol.findLongestWord(s, dictionary);
        printf("result: %s\n", output.c_str());
    }

    return 0;
}