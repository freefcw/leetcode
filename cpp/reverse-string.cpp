#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() < 2) {
            return;
        }
        char ch;
        int len = s.size() - 1;
        for (int i = 0; i < len; ++i)
        {
            if ( i < len - i) {
                ch = s[i];
                s[i] = s[len - i];
                s[len - i] = ch;
            }
        }
    }
};

int main()
{
    char chars[] = {'h','e','l','l','o'};
    std::vector<char> items(chars, chars + 5);
    Solution s;
    s.reverseString(items);
    for (int i = 0; i < 5; ++i)
    {
        cout << items[i] << endl;
    }

    return 0;
}