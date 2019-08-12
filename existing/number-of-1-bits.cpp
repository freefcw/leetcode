#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(true) {
            if (n < 2) {
                if (n == 1) {
                    count++;
                }
                break;
            }
            if (n % 2 == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;


    return 0;
}