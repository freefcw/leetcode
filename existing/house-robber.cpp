#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int total = nums.size();
        if (total == 0) {
            return 0;
        }
        vector<int> maxr(total);

        for(int i = 0; i < total; i++) {
            int max2 = 0;
            int max3 = 0;
            if (i - 2 >= 0) {
                max2 = maxr[i - 2];
            }
            if (i - 3 >= 0) {
                max3 = maxr[i - 3];
            }
            if (max2 > max3) {
                maxr[i] = nums[i] + max2;
            } else {
                maxr[i] = nums[i] + max3;
            }
            cout << i << ":" << maxr[i] << "|" << nums[i] << endl;
        }
        if (total == 1) {
            return maxr[0];
        }
        if (maxr[total - 1] > maxr[total - 2]) {
            return maxr[total - 1];
        }
        return maxr[total - 2];
    }

    int rob2(vector<int>& nums) {
        int a = this->robit(nums, nums.size() - 1);
        int b = this->robit(nums, nums.size() - 2);
        if (a > b) {
            return a;
        }
        return b;
    }

    int robit(vector<int>& nums, int end)
    {
        if (end < 0) {
            return 0;
        }
        int a = nums[end] + this->robit(nums, end - 2);
        int b = nums[end] + this->robit(nums, end - 3);
        if (a > b) {
            return a;
        }
        return b;
    }
};


int main()
{
    Solution s;
    int nums[] = {2, 3};
    vector<int> vn(nums, nums + 2);
    cout << s.rob(vn) << endl;

    return 0;
}