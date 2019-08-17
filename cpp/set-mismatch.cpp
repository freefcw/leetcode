#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = 0;
        int missing = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -1 * nums[x - 1];
            } else {
                dup = x;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        vector<int> result;
        result.push_back(dup);
        result.push_back(missing);
        return result;
    }
};

class Solution3 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        int found = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+= nums[i];
            if (i < nums.size() -1 && nums[i] == nums[i+1]) {
                found = nums[i];
            }
        }

        int expect = (1 + nums.size()) * nums.size() / 2;
        int lost = expect - sum + found;
        vector<int> result;
        result.push_back(found);
        result.push_back(lost);
        return result;
    }
};

class Solution2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> ss;
        int found = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+= nums[i];
            if (found < 0) {
                if (ss.find(nums[i]) == ss.end()) {
                    ss.insert(nums[i]);
                } else {
                    found = nums[i];
                }
            }
        }

        int expect = (1 + nums.size()) * nums.size() / 2;
        int lost = expect - sum + found;
        vector<int> result;
        result.push_back(found);
        result.push_back(lost);
        return result;
    }
};


int main()
{
    Solution s;
    int nums[] = {1,2,2,4};
    vector<int> vn(nums, nums + 4);
    
    vector<int> v = s.findErrorNums(vn);
    for (int i = 0; i < 2; i++) {
        cout << v[i] << endl;
    }

    return 0;
}