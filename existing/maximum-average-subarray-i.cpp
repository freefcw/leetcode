#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;


class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        long int sum = 0;
        long int max = 0;
        for(int i = 0;i < nums.size();i++) {
            if (i < k) {
                sum += nums[i];
                max = sum;
                continue;
            }
            sum = sum + nums[i] - nums[i - k];
            if (sum > max) {
                max = sum;
            }
        }
        return max * 1.0 / k;
    }
};

int main()
{
    Solution s;
    int nums[] = { 1,
                   12,
                   -5,
                   -6,
                   50,
                   3 };
    vector<int> vn(nums, nums + 6);
    cout << s.findMaxAverage(vn, 4) << endl;

    return 0;
}