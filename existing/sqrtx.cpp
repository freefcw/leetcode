#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long int min = 1;
        long int max = x;
        long int current;
        while (true) {
            current = (min + max) / 2;
            if (current * current > x) {
                max = current;
                continue;
            }
            if (current * current == x) {
                return current;
            }
            if (current * current < x && (current + 1) * (current + 1) > x) {
                return current;
            }
            min = current;
        }
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(8) << endl;
    cout << s.mySqrt(101) << endl;
    cout << s.mySqrt(1000) << endl;


    return 0;
}