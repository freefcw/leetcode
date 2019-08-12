#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) {
            return true;
        }
        if (num < 4) {
            return false;
        }
        while(true) {
            if (num == 1) {
                return true;
            }
            if (num < 4) {
                return false;
            }

            if (num % 4 != 0) {
                return false;
            }
            num = num / 4;
        }
    }
};
int main()
{
    Solution s;
    cout << s.isPowerOfFour(1) << endl;
    cout << s.isPowerOfFour(16) << endl;
    cout << s.isPowerOfFour(5) << endl;
    cout << s.isPowerOfFour(128) << endl;
    cout << s.isPowerOfFour(0) << endl;
    return 0;
}