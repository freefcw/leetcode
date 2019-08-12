#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i)
        {
            s = this->sayIt(s);
        }
        return s;
    }

    string sayIt(string it) {
        if (it.length() == 1) {
            return "11";
        }

        int count = 1;
        string result = "";
        char last = it.front();
        for (int i = 1; i < it.length(); ++i)
        {
            if (it[i] != last) {
                result += this->countIt(count, last);
                last = it[i];
                count = 1;
                continue;
            }
            count++;
        }
        result += this->countIt(count, last);
        return result;
    }
    string countIt(int count, char ch) {
        char buff[10];
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%d%c", count, ch);
        return buff;
    }
};

int main()
{
    Solution s;
    cout << s.sayIt("1") << endl;
    cout << s.sayIt("11") << endl;
    cout << s.sayIt("21") << endl;
    cout << s.sayIt("1211") << endl;
    cout << s.sayIt("111221") << endl;


    cout << s.countAndSay(4) << endl;

    return 0;
}