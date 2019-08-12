#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long int newNum = x % 10;
        long int left = x / 10;

        while(true) {
            if (left == 0) {
                break;
            }
            newNum = newNum * 10+ left % 10;

            left = left / 10;
        }
        if (newNum == x) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(1) << endl;
    cout << s.isPalindrome(-1) << endl;
    cout << s.isPalindrome(10) << endl;
    cout << s.isPalindrome(121) << endl;


    return 0;
}