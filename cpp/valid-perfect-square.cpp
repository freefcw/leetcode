#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i;
        unsigned int MAX_INT = (1 << 31);
        for (i = 1; i <= num; ++i)
        {
            if (MAX_INT / i < i) {
                return false;
            }
            if (i * i == num) {
                return true;
            }
            if (i * i > num) {
                return false;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isPerfectSquare(1) << endl;
    cout << s.isPerfectSquare(16) << endl;
    cout << s.isPerfectSquare(5) << endl;
    cout << s.isPerfectSquare(8) << endl;
    cout << s.isPerfectSquare(25) << endl;

    return 0;
}