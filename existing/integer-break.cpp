#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if ( n < 4) {
            return n - 1;
        }
        if (n == 4) {
            return 4;
        }
        int left = n % 3;
        int total = n / 3;
        if (left == 1) {
            total = total - 1;
            left = 4;
        }
        if (left == 0) {
            left = 1;
        }
        return pow(3, total) * left;
    }
};

int main()
{
    Solution s;
    cout << s.integerBreak(8) << endl;

    return 0;
}