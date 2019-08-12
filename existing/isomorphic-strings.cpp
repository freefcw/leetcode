#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        for(int i = 0; i < s.size(); i++) {
            for(int k = 0; k < i; k++) {
                if (s[i] == s[k] && t[i] == t[k]) {
                    break;
                }
                if (s[i] == s[k] && t[i] != t[k]) {
                    return false;
                }
                if (t[i] == t[k] && s[i] != s[k]) {
                    return false;
                }
            }
        }

        return true;
    }
};
int main()
{
    Solution s;

    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    cout << s.isIsomorphic("ab", "aa") << endl;

    return 0;
}