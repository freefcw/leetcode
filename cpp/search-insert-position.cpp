#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums.back()) {
            return nums.size();
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (target <= nums[i]) {
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;

    int ch[] = {3,8,11,23};
    vector<int> chars(ch, ch + 4);
    int ret = s.searchInsert(chars, 0);
    cout << ret << endl;

    return 0;
}