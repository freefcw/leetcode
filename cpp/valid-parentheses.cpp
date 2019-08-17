#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        vector<char> stack;
        for (int i = 0; i < s.size(); ++i)
        {
            // cout << s[i] << endl;
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push_back(s[i]);
            }
            if (s[i] == ')') {
                if (stack.size() == 0) {
                    return false;
                }
                if (stack.back() != '(') {
                    return false;
                } else {
                    stack.pop_back();
                }
            }
            if (s[i] == ']') {
                if (stack.size() == 0) {
                    return false;
                }
                if (stack.back() != '[') {
                    return false;
                } else {
                    stack.pop_back();
                }
            }
            if (s[i] == '}') {
                if (stack.size() == 0) {
                    return false;
                }
                if (stack.back() != '{') {
                    return false;
                } else {
                    stack.pop_back();
                }
            }
        }
        if (stack.size() > 0) {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("){") << endl;

    return 0;
}