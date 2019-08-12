#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> passed;
        for (int i = 0; i < nums.size(); i++) {
            if (passed.find(nums[i]) == passed.end()) {
                passed.insert(nums[i]);
            } else {
                return nums[i];
            }
        }

        return 0;
    }
};

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int k = i + 1; k < nums.size(); k++) {
                if (nums[i] == nums[k]) {
                    return nums[i];
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    int nums[] = {2,2,2,2,2};
    vector<int> vn(nums, nums + 5);
    
    cout << s.findDuplicate(vn) << endl;;
    

    return 0;
}