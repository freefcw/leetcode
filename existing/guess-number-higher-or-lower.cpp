#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int guess(int num)
{
    if (num > 1) {
        return -1;
    }
    if (num < 1) {
        return 1;
    }

    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        long int min = 1, max = n;
        long int current;
        if (guess(min) == 0) {
            return min;
        }
        if (guess(max) == 0) {
            return max;
        }
        while (true) {
            current = (min + max) / 2;
            int ret = guess(current);
            if (ret == 1) {
                min = current;
                continue;
            }
            if (ret == -1) {
                max = current;
                continue;
            }
            return current;
        }
    }
};

int main()
{
    Solution s;
    cout << s.guessNumber(2) << endl;


    return 0;
}