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
    string minWindow(string s, string t) {
        // bool flags[128] = { false };
        // char chars[128] = { 0 };
        vector<int> chars(128, 0);
        vector<bool> flags(128, false);
        for (int i = 0; i < t.size(); i++) {
            flags[t[i]] = true;
            chars[t[i]]++;
        }

        int count = 0;
        int minSize = s.length() + 1;
        int l = 0;
        int minL = 0;

        for (int r = 0; r < s.length(); r++) {
            char cr = s[r];
            if (flags[cr]) {
                if (--chars[cr] >= 0)
                    count++;
                while (count == t.size()) {
                    char cl = s[l];
                    if (r - l + 1 < minSize) {
                        minSize = r - l + 1;
                        minL = l;
                    }
                    if (flags[cl] && ++chars[cl] > 0) {
                        count--;
                    }
                    l++;
                }
            }
        }
        return minSize > s.size() ? "" : s.substr(minL, minSize);
    }
};

int main()
{
    Solution sol;
    {
        string s = "ADOBECODEBANC", t = "ABC";
        string target = sol.minWindow(s, t);
        printf("the target string is %s\n", target.c_str());
    }
    {
        string s = "wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon", t = "ozgzyywxvtublcl";
        string target = sol.minWindow(s, t);
        printf("the target string is %s\n", target.c_str());
    }

    return 0;
}