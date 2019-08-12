#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
// 思路2排序后再做
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = nums[0];
        int max_count = 1;
        int current = nums[0];
        int current_count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == current) {
                current_count++;
            } else {
                current = nums[i];
                current_count = 1;
            }
            if (current_count > max_count) {
                max = nums[i];
                max_count = current_count;
            }
            if (max_count * 2 >= nums.size()) {
                return max;
            }
        }
        return max;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> eleMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (eleMap.find(nums[i]) != eleMap.end()) {
                auto count = eleMap[nums[i]];
                if (count*2 > nums.size()) {
                    return nums[i];
                }
                eleMap[nums[i]]++;
            } else {
                eleMap[nums[i]] = 1;
            }
        }
        int max = 0;
        for (auto it = eleMap.begin(); it != eleMap.end(); ++it)
        {
            if (it->second > eleMap[max]) {
                max = it->first;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    int nums[] = {2,2,1,1,1,2,2};
    vector<int> vn(nums, nums + 7);
    cout << s.majorityElement(vn) << endl;

    return 0;
}