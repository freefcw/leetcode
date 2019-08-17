#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string result;
        int pos = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') {
                continue;
            }
            if (pos > 0 && pos % k == 0) {
                result.push_back('-');
            }
            result.push_back(toupper(s[i]));
            pos++;
        }
        string newresult(result.rbegin(), result.rend());
        return newresult;
    }
};

int main()
{
    Solution s;
    cout << s.licenseKeyFormatting("2-5g-3-J", 2) << endl;
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 3) << endl;
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 8) << endl;

    return 0;
}