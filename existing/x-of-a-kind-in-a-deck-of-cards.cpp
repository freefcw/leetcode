#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int numCount[10000];
        for(int i = 0; i < 10000; i++) {
            numCount[i] = 0;
        }
        for(int i = 0; i < deck.size(); i++) {
            numCount[deck[i]]++;
        }
        int maxg = 0;
        for(int i = 0; i < 10000; i++) {
            if (maxg == 0) {
                maxg = numCount[i];
            } else {
                maxg = this->gcd(maxg, numCount[i]);
                if (maxg < 2) {
                    return false;
                }
            }
        }
        return maxg >= 2;
    }

    int gcd(int x, int y)
    {
        if (x == 0) {
            return y;
        }
        return this->gcd(y % x, x);
    }
};

int main()
{
    Solution s;



    return 0;
}