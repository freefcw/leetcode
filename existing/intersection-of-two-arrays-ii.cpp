#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mm;
        vector<int> result;
        for(int i = 0; i < nums1.size(); i++) {
            if (mm.find(nums1[i]) != mm.end()) {
                mm[nums1[i]] = mm[nums1[i]] + 1;
            } else {
                mm[nums1[i]] = 1;
            }
        }
        for(int i = 0; i < nums2.size(); i++) {
            if (mm.find(nums2[i]) != mm.end() && mm[nums2[i]] > 0) {
                mm[nums2[i]] = mm[nums2[i]] - 1;
                result.push_back(nums2[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    int n[] = {2,4,0,0,1};
    vector<int> v1(n, n + 5);
    int n1[] = {2,0,3,0,2};
    vector<int> v2(n1, n1 + 5);
    vector<int> ret = s.intersect(v1, v2);
    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
    
    return 0;
}