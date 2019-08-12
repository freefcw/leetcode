#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<char> bits;
        while(true) {
            if (n < 2) {
                bits.push_back(n);
                break;
            }
            bits.push_back(n % 2);
            n = n >> 1;
        }
        for(int i = bits.size(); i < 32; i++) {
            bits.push_back(0);
        }
        uint32_t result = 0;
        for(int i = 0; i < bits.size(); i++) {
            // cout << (int)bits[i];
            result = (result << 1) + (int)bits[i];
        }
        // cout << endl;
        // cout << result << endl;
        return result;
    }
};

int main()
{
    Solution s;
    s.reverseBits(43261596);
    s.reverseBits(964176192);
    s.reverseBits(4294967293);
    s.reverseBits(3221225471);
    s.reverseBits(0);
    s.reverseBits(1);

    return 0;
}