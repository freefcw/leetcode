#include <cstdio>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    int addDigits(int n) {
        if (n < 10) {
            return n;
        }
        int mod = n % 9;
        if (mod == 0) {
            return 9;
        }
        return mod;
    }
};


class Solution1 {
public:
    int addDigits(int n) {
        if (n < 10) {
            return n;
        }
        int sum = 0;
        while(true) {
            int mod = n % 10;
            sum += mod;
            if (n > 9) {
                n = n / 10;
                continue;
            }
            break;
        }
        return this->addDigits(sum);
    }
};

int main()
{
    Solution s;
    for (int i = 0; i < 100; ++i)
    {
        cout << i << ":" << s.addDigits(i) << endl;
    }

    return 0;
}