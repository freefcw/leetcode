#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        unsigned int sum = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            sum = sum * 26 + s[i] - 'A' + 1;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("AB") << endl;
    cout << s.titleToNumber("ZY") << endl;
    cout << s.titleToNumber("AZ") << endl;


    return 0;
}