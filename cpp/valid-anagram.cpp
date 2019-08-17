#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> charCount(26, 0);
        for(int i = 0; i < s.size(); i++) {
            charCount[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            int p = t[i] - 'a';
            charCount[p]--;
            if (charCount[p] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("anagram", "nagaram") << endl;
    cout << s.isAnagram("rat", "car") << endl;
    cout << s.isAnagram("", "c") << endl;
    return 0;
}