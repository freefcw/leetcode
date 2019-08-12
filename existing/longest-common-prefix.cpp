#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string currentMax = strs.front();
        for (std::vector<string>::iterator str = strs.begin(); str != strs.end(); ++str)
        {
            currentMax = this->findCommonPrefix(currentMax, *str);
        }
        return currentMax;
    }

    string findCommonPrefix(string str1, string str2) {
        int max_length = str1.length();
        if (str1.length() > str2.length()) {
            max_length = str2.length();
        }
        for (int i = 0; i < max_length; ++i)
        {
            if (str1[i] != str2[i]) {
                return str1.substr(0, i);
                break;
            }
        }
        return str1.substr(0, max_length);
    }
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    cout << s.longestCommonPrefix(strs) << endl;
    vector<string> strs2;
    strs2.push_back("dog");
    strs2.push_back("flower");
    cout << s.longestCommonPrefix(strs2) << endl;

    vector<string> strs3;
    cout << s.longestCommonPrefix(strs3) << endl;
    // cout << s.findCommonPrefix("abc", "abecde") << endl;

    return 0;
}