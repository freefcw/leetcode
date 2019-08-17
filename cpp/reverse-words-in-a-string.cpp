#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                word.push_back(s[i]);
            }
            if (s[i] == ' ' && word.size() > 0) {
                words.push_back(word);
                word = "";
            }
        }
        if (word.size() > 0) {
            words.push_back(word);
        }
        string result;
        for(vector<string>::reverse_iterator it = words.rbegin(); it != words.rend(); it++) {
            if (result.size() > 0) {
                result.append(" ");
            }
            result.append(*it);
        }

        return result;
    }
};

int main()
{
    Solution s;

    cout << s.reverseWords("    hello world!   ") << endl;

    return 0;
}