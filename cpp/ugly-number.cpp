#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) {
            return false;
        }
        while(num % 2 == 0) {num = num / 2;};
        while(num % 3 == 0) {num = num / 3;};
        while(num % 5 == 0) {num = num / 5;};
        if (num == 1){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 100; ++i)
    {
        cout << i << ":" << s.isUgly(i) << endl;
    }


    return 0;
}