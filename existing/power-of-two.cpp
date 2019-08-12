#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) {
            return false;
        }
        unsigned int MAX = 1 << 31;
        return MAX % n == 0;
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfTwo(0) << endl;
    cout << s.isPowerOfTwo(1) << endl;
    cout << s.isPowerOfTwo(2) << endl;
    cout << s.isPowerOfTwo(4) << endl;
    cout << s.isPowerOfTwo(1229) << endl;

    return 0;
}