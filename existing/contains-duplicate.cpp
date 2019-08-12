#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> remembers;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (remembers.find(nums[i]) == remembers.end()) {
                remembers.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    int nums[] = {1,2,3,4};
    vector<int> vn(nums, nums + 4);
    cout << s.containsDuplicate(vn) << endl;

    return 0;
}