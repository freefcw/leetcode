
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        if (n < 5) {
            return false;
        }
        // cout << n << endl;
        int sum = 0;
        while(true) {
            int mod = n % 10;
            sum += mod * mod;
            if (n > 9) {
                n = n / 10;
                continue;
            }
            break;
        }
        return this->isHappy(sum);
    }
};

int main()
{
    Solution s;
    for (int i = 0; i < 100; ++i)
    {
        cout << i << ":" << s.isHappy(i) << endl;
    }

    return 0;
}