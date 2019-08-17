#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        string word;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                for(int i = word.size() - 1; i >= 0; i--) {
                    result.push_back(word[i]);
                }
                result.push_back(' ');
                word.clear();
                continue;
            }
            word.push_back(s[i]);
        }
        for(int i = word.size() - 1; i >= 0; i--) {
            result.push_back(word[i]);
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;
    cout << s.reverseWords("Let") << endl;
    cout << s.reverseWords("Let efc ") << endl;
    
    return 0;
}