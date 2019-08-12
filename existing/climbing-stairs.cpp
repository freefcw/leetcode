#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        vector<int> solutions(n + 1);
        solutions[0] = 0;
        solutions[1] = 1;
        solutions[2] = 2;
        for (int i = 3; i < n; ++i)
        {
            solutions[i] = solutions[i-1] + solutions[i - 2];
        }
        return solutions[n - 1] + solutions[n - 2];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(4) << endl;

    return 0;
}