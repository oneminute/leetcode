/*
*
* https://leetcode.com/problems/longest-substring-without-repeating-characters/
* Given a string data, find the length of the longest substring without repeating characters.
* 
*
* Example 1:
*
*    Input: data = "abcabcbb"
*    Output: 3
*    Explanation: The answer is "abc", with the length of 3.
*
* Example 2:
*
*    Input: data = "bbbbb"
*    Output: 1
*    Explanation: The answer is "b", with the length of 1.
*
* Example 3:
*
*    Input: data = "pwwkew"
*    Output: 3
*    Explanation: The answer is "wke", with the length of 3.
*    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
* 
*
* Constraints:
*
*    0 <= data.length <= 5 * 104
*    data consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <unordered_map>
#include <SimpleTest.h>

using namespace std;

int lengthOfLongestSubstring(string data) {
    vector<int> indicesTable(128, 0);
    int maxLength = 0;
    int head = 0;
    for (int tail = 0; tail < data.size(); tail++) {
        char currChar = data[tail];
        head = max(head, indicesTable[currChar]);
        indicesTable[currChar] = tail + 1;
        maxLength = max(maxLength, tail - head + 1);
    }
    return maxLength;
}

int main()
{
    st::TestRunner runner;
    runner.addTask(new st::TestCase("Test01", "abc def", "abc"));
    runner.addTask(new st::TestCase("Test02", "bca fed", "dba"));
    runner.start();
    // cout << lengthOfLongestSubstring("abcadefgisadeg") << endl;
    std::string a;
    std::cin >> a;
    std::cin >> a;
    std::cout << "abc" << std::endl;
    runner.check();
    std::cin >> a;
    std::cin >> a;
    std::cout << "dba" << std::endl;
    runner.check();
    runner.finish();

    return 0;
}