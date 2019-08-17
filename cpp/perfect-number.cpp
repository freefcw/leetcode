#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num < 6) {
            return false;
        }
        int sum = 1;
        int max = num;
        int i = 2;
        int amax = sqrt(num);
        while(i < max) {
            if (num % i == 0) {
                // cout << '=' << i << num / i << endl;
                sum += i;
                sum += num / i;
                max = num / i;
            }
            if (i >= amax) {
                break;
            }
            i++;
        }
        return sum == num;
    }
};

int main()
{
    Solution s;
    cout << s.checkPerfectNumber(28) << endl;
    for(int i = 5; i < 100000000; i ++) {
        if (s.checkPerfectNumber(i)) {
            cout << i << endl;
        }
    }
    
    
    return 0;
}