#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int size2 = haystack.size() - needle.size();
        int len_n = needle.size();
        for (int i = 0; i <= size2; ++i)
        {
            if (haystack[i] == needle[0]) {
                if (haystack[i + len_n - 1] != needle[len_n - 1]) {
                    continue;
                }
                bool isSame = true;
                for (int k = 1; k < len_n; ++k)
                {
                    if (i+k > haystack.size()) {
                        return false;
                    }
                    // cout << haystack[i+k] << "|" << needle[k] << endl;
                    if (haystack[i+k] != needle[k]) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("3331lllrrr", "lll") << endl;

    return 0;
}