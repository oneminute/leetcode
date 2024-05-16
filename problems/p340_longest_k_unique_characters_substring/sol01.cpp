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
    int longestKSubstr(string s, int k) {
        int n = -1;
        int charMap[26];
        for (int i = 0; i < 26; i++)
            charMap[i] = -1;
        int i = 0, j = 0;
        int start = 0, end = 0, length = 0;
        int count = 0;
        while (true) {
            int ci = s[i] - 'a';
            int cj = s[j] - 'a';
            if (charMap[cj] == -1) {
                count++;
            }
            charMap[cj] = j;
            if (count > k) {
                if (j - i > length) {
                    length = j - i;
                    start = i;
                    end = j;
                }
                while (count > k && i <= j) {
                    ci = s[i] - 'a';
                    if (charMap[ci] == i) {
                        count--;
                        charMap[ci] = -1;
                    }
                    i++;
                }
            }
            j++;
            if (j == s.length()) {
                if (count == k) {
                    if (j - i > length) {
                        length = j - i;
                        start = i;
                        end = j;
                    }
                }
                break;
            }
        }
        return count == k ? length : -1;
    }
};

int main()
{
    Solution s;
    {
        string str = "aabacbebebe";
        int k = 3;
        int n = s.longestKSubstr(str, k);
        cout << "n = " << n << endl;
    }
    {
        string str = "aaaa";
        int k = 2;
        int n = s.longestKSubstr(str, k);
        cout << "n = " << n << endl;
    }
    {
        string str = "joizyglhbetjlvglzvvktxqsslufceppzpgogrifbeyuiblmgcqtkhhbimxigczvbtvrtsperlhunsyywgnttbwjgunjwjtqzqvrdumddtzaffcmjlakmfappoqqkvmfnevaabqxtzslodalgvtwvbsknohmjcumrrqktskvidbizexkprdonsjkbcoeplcafdalmvfaswnjkiqcwowhykczbdkankmkrrwsmcomaubfelnljztemcbmmoptndjodpqnikglvraezkvfxcphvgdgkouirhidbdtesjogrilbxhgtqprexyxptbqdxnwsuddzoiuumlbbgmhuzbgaslssvtexzlipsqfrfvxbkxmazocqvtaguvxmoqvhkfklucswkizrpatpakmuswqdsmxtnuujewtwtrnofowrgmxegwkxokotqhfodaegkmopjpdvpxzjrunwfqeldjhajnjzaargszgxakniopptsoakustvpbtocrovfceofpbeddqeidyvosbwbspesilldkdvocbfrbzthbgsnzaabjfbeanwoicritttjvkromyiodiazfgzktgkeqjmojamqrdusaibheiivnvmokacqudrcairqtisixcjxjsdubgusrcpleludvkjiabbeukbeadqruccuhwcrgosagtuyjfhnaniapxkrqdbmdsbxrzriyszsoguditxxpvdopzktljyrdzxunnybfzfqoezhizbustnwlpqypfqtgxapvwrcybnsjfrsdhyafsdglucczqtoazaycxybnlratmdqphtdwqsddhkrhvbgsytp";
        int k = 10;
        int n = s.longestKSubstr(str, k);
        cout << "n = " << n << endl;
    }
    printf("\n");
    return 0;
}