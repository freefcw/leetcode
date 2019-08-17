#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int sum = nums[0];
        int max = nums[0];
        for (int i = 1; i < len; ++i)
        {
            // cout << sum  << "|" << max << endl;
            if (sum < 0) {
                sum = 0;
            }
            if (sum + nums[i] < 0) {
                sum = 0;
            }
            sum = sum + nums[i];
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    int nums[] = {-2,-1};//,-3,4,-1,2,1,-5,4};
    vector<int> vn(nums, nums+2);
    cout << s.maxSubArray(vn) << endl;

    return 0;
}