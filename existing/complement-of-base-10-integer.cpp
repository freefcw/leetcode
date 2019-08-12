#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        int bitsize = 0;
        while(true) {
            if ((1 << bitsize) > N) {
                break;
            }
            bitsize++;
        }
        return N ^ ((1 << bitsize) - 1);
    }
};

class Solution2 {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        vector<char> bits;

        while(N > 0) {
            int bit = N & 1;
            N = N >> 1;
            if (bit == 1) {
                bits.push_back(0);
            } else {
                bits.push_back(1);
            }
        }
        long dest = 0;
        for (int i = 0; i < bits.size(); i++) {
            dest += bits[i] << i;
        }
        return dest;
    }
};


int main()
{
    Solution s;

    cout << s.bitwiseComplement(5) << endl;
    cout << s.bitwiseComplement(7) << endl;
    cout << s.bitwiseComplement(10) << endl;
    cout << s.bitwiseComplement(1) << endl;
    cout << s.bitwiseComplement(0) << endl;

    return 0;
}