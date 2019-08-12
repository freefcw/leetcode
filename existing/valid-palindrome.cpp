#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) {
            return true;
        }
        string s2;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isalnum(s[i])) {
                s2.push_back(tolower(s[i]));
            }
        }
        // cout << s2 << endl;
        int len = s2.size();
        for (int i = 0; i < len; ++i) {
            int op = len - i - 1;
            if (op > i) {
                if (s2[i] != s2[op]) {
                    return false;
                }
            }
            if (op <= i) {
                return true;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    // cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    // cout << s.isPalindrome("a") << endl;
    // cout << s.isPalindrome("aA") << endl;
    // cout << s.isPalindrome("") << endl;
    // cout << s.isPalindrome("aaa") << endl;
    // cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome("OP") << endl;


    return 0;
}