#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int total = 0;
        while(true) {
            total += n / 5;
            n = n / 5;
            if (n < 5) {
                break;
            }
        }
        return total;
    }
};

int main()
{
    Solution s;
    cout << s.trailingZeroes(1808548329) << endl;

    return 0;
}