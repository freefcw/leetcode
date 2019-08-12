#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) {
            return a;
        }
        int sum = a ^ b;
        int carry = (a&b) << 1;
        cout << sum << "||" << carry << endl;
        return this->getSum(sum, carry);
    }
};

int main()
{
    Solution s;
    cout << s.getSum(-1, 1) << endl;
    cout << s.getSum(-2, 1) << endl;
    cout << s.getSum(-3, 1) << endl;

    return 0;
}