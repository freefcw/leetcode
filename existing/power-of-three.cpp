#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int num) {
        if (num == 1) {
            return true;
        }
        if (num < 3) {
            return false;
        }
        while(true) {
            if (num == 1) {
                return true;
            }
            if (num < 3) {
                return false;
            }

            if (num % 3 != 0) {
                return false;
            }
            num = num / 3;
        }
    }
};
int main() {
    s Solution;
    s.isPowerOfThree(1);
}