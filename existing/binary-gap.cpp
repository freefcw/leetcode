#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int maxDist = 0;
        int dist = 0;
        bool started = false;
        while(N > 0) {
            int bit = N & 1;
            N = N >> 1;
            if (bit == 1) {
                started = true;
                if (started && dist > maxDist) {
                    maxDist = dist;
                }
                dist = 1;
            } else {
                if (started) {
                    dist++;
                }
            }
        }

        return maxDist;
    }
};


class Solution2 {
public:
    int binaryGap(int N) {
        vector<char> bits;

        while(N > 0) {
            int bit = N & 1;
            bits.push_back(bit);
            N = N >> 1;
        }
        int maxDist = 0;
        int dist = 0;
        for(int i = bits.size() - 1; i >= 0 ; i--) {
            cout << (int)bits[i] << endl;
            if (bits[i] == 1) {
                if (dist > maxDist) {
                    maxDist = dist;
                }
                dist = 1;
            } else {
                dist++;
            }
        }
        return maxDist;
    }
};


int main()
{
    Solution s;

    cout << s.binaryGap(5) << endl;
    // cout << (4 & 1) << endl;
    // cout << (3 & 1) << endl;

    return 0;
}