#include <cstdio>
#include <vector>
#include <string>
#include <cwchar>
#include <iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0) {
            return 0;
        }
        int pos = 0;
        int count = 1;
        int length = chars.size();
        for (int i = 0; i < length; ++i)
        {
            if (pos == i) {
                continue;
            }
            if (chars[i] == chars[pos]) {
                count++;
                continue;
            }
            if (count == 1) {
                pos++;
            } else {
                string a = this->parseCount(count);
                // cout << '|' << a << endl;
                for (int k = 0; k < a.size(); ++k)
                {
                    // cout << ':' << a[k] << endl;
                    chars[pos + 1 + k] = a[k];
                }
                // chars[pos + 1] = 0x30 + count;
                pos += a.size() + 1;
            }
            count = 1;
            chars[pos] = chars[i];
        }
        if (count == 1) {
            pos++;
        } else {
            string a = this->parseCount(count);
            // cout << '|' << a << endl;
            for (int k = 0; k < a.size(); ++k)
            {
                chars[pos + 1 + k] = a[k];
            }
            pos += a.size() + 1;
        }

        return pos;
    }
    string parseCount(int count) {
        char buff[5];
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%d", count);
        return string(buff);
    }
};

int main()
{
    Solution s;
    // cout << s.parseCount(0) << endl;
    // cout << s.parseCount(1) << endl;
    // cout << s.parseCount(9) << endl;
    // cout << s.parseCount(1000) << endl;
    char ch[] = {'a','a','b','b','c','c','c','d', 'd'};
    vector<char> chars(ch, ch + sizeof(ch));
    int ret = s.compress(chars);
    // cout << ret << endl;
    for (int i = 0; i < ret; ++i)
    {
        cout << chars[i];// << endl;
    }


    return 0;
}