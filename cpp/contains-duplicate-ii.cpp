#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> numsmap;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto item = numsmap.find(nums[i]);
            if (item != numsmap.end()) {
                // cout << item->first << ":" << item->second << endl;
                if ( i - item->second > k) {
                    numsmap[nums[i]] = i;
                } else {
                    return true;
                }
            } else {
                numsmap[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int nums[] = {1,2,3,4,5,6,7,8,9,9};
    vector<int> vn(nums, nums + 10);
    cout << s.containsNearbyDuplicate(vn, 3) << endl;

    return 0;
}