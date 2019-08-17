#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        int pos = s.find('@');
        if (pos != string::npos) {
            return this->maskingEmail(s, pos);
        }
        string digits = this->leavedigits(s);
        if (digits.size() == 10) {
            return this->maskPhone10(digits);
        }
        if (digits.size() >= 10) {
            return this->maskPhone12(digits);
        }

        return "";
    }

    string leavedigits(string s) {
        string left;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i])) {
                left.push_back(s[i]);
            }
        }
        
        return left;
    }

    string maskingEmail(string s, int pos) {
        string postfix = s.substr(pos);
        // int dot_pos = s.find_first_of('.');
        // if (dot_pos == string::npos || (dot_pos != s.find_last_of('.'))) {
        //     return s;
        // }
        for (int i = 0; i < postfix.size(); i++)
        {
            postfix[i] = tolower(postfix[i]);
        }
        char a = tolower(s[0]);
        char b = tolower(s[pos - 1]);
        char buff[8];
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%c*****%c", a, b);

        return string(buff) + postfix;
    }

    string maskPhone10(string s) {
        string res = "***-***-" + s.substr(6);

        return res;
    }

    string maskPhone12(string s) {
        int pos = s.size() - 4;
        int prefix_count = s.size() - 10;
        string prefix(prefix_count, '*');
        string res = "+" + prefix + "-***-***-" + s.substr(pos);

        return res;
    }
};

int main()
{
    Solution s;
    // cout << s.maskPII("ababab") << endl;
    cout << s.maskPII("abababc@qq.com") << endl;
    cout << s.maskPII("ABCD@qq.com") << endl;
    cout << s.maskPII("AB@QQ.com") << endl;
    cout << s.maskPII("A@QQ.com") << endl;
    cout << s.maskPII("1(234)567-890") << endl;
    cout << s.maskPII("86-(10)12345678") << endl;
    cout << s.maskPII("+(501321)-50-23431") << endl;
    cout << s.maskPII("+(52201321)-50-23431") << endl;


    return 0;
}