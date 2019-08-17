#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int max_len = 0;
        bool new_start = true;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ') {
                if (new_start) {
                    max_len = 0;
                }
                max_len++;
                new_start = false;
                continue;
            }
            new_start = true;
        }

        return max_len;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("Hello ") << endl;
    cout << s.lengthOfLastWord(" ") << endl;
    cout << s.lengthOfLastWord(" World") << endl;

    return 0;
}