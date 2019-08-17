#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = -1;
        int pc = 0;
        while(true) {
            if(pc == nums.size()) {
                break;
            }
            // cout << pc << endl;
            if (nums[pc] == 0 && p1 == -1) {
                p1 = pc;
            }
            if (nums[pc] != 0 && p1 >= 0) {
                nums[p1] = nums[pc];
                p1++;
                nums[pc] = 0;
            }
            pc++;
        }
    }
};

int main()
{
    Solution s;
    int n[] = {2,0,0,0,1};
    vector<int> v(n, n + 5);
    s.moveZeroes(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    return 0;
}