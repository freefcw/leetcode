#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int total = cost.size();
        if (total < 2) {
            return 0;
        }
        vector<int> solutions(total);
        solutions[0] = cost[0];
        solutions[1] = cost[1];
        for (int i = 2; i < total; ++i)
        {
            if (solutions[i-1] < solutions[i-2]) {
                solutions[i] = solutions[i-1] + cost[i];
            } else {
                solutions[i] = solutions[i-2] + cost[i];
            }
        }
        if (solutions[total - 2] < solutions[total - 1]) {
            return solutions[total - 2];
        }
        return solutions[total - 1];
    }
};



int main()
{
    Solution s;
    int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> nums(a, a + 10);
    cout << s.minCostClimbingStairs(nums) << endl;

    return 0;
}