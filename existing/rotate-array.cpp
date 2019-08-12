#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2) {
            return;
        }
        vector<int >nums2(len);
        for (int i = 0; i < len; ++i)
        {
            if (i + k < len) {
                nums2[i+k] = nums[i];
            } else {
                nums2[(i+k) % len] = nums[i];
            }
        }
        nums.clear();
        nums.assign(nums2.begin(), nums2.end());
    }
};

int main()
{
    Solution s;

    return 0;
}