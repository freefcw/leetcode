#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;
        for (int i = 0; i < nums1.size(); ++i)
        {
            set1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (set1.find(nums2[i]) != set1.end()) {
                set2.insert(nums2[i]);
            }
        }
        nums2.clear();
        nums2.insert(nums2.begin(), set2.begin(), set2.end());
        // result = new std::vector<int>(set2.begin(), set2.end());
        return nums2;
    }
};

int main()
{
    Solution s;
    

    return 0;
}