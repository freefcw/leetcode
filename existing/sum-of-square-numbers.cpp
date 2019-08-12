#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long max = ceil(sqrt(c));
        for (long i = max; i >= 0; i--)
        {
            long a2 = i * i;
            if (a2 > c)
            {
                continue;
            }
            long b2 = c - a2;
            long b = ceil(sqrt(b2));

            if (b * b == b2 || (b - 1) * (b - 1) == b2)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    // cout << s.judgeSquareSum(5) << endl;
    // cout << s.judgeSquareSum(4) << endl;
    // cout << s.judgeSquareSum(13) << endl;
    cout << s.judgeSquareSum(2) << endl;

    return 0;
}