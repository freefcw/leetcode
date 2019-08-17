#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char sets[26];
        for (int i = 0; i < 26; i++)
        {
            sets[i] = 0;
        }

        for (int i = 0; i < s.size(); i++)
        {
            int pos = s[i] - 'a';
            sets[pos]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            int pos = t[i] - 'a';
            sets[pos]--;
            if (sets[pos] < 0) {
                return t[i];
            }
        }
        return ' ';
    }
};

int main()
{
    Solution s;
    cout << s.findTheDifference("abcd", "abcde") << endl;
    cout << s.findTheDifference("abcd", "abcda") << endl;
    return 0;
}