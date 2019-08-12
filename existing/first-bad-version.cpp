#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

bool isBadVersion(int version)
{
    if (version > 100) {
        return true;
    }
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) {
            return 1;
        }
        long int min = 1, max = n;
        long int current;
        while (true) {
            if (min == max - 1) {
                return max;
            }
            current = (min + max) / 2;
            if (isBadVersion(current)) {
                max = current;
            } else {
                min = current;
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.firstBadVersion(101) << endl;


    return 0;
}