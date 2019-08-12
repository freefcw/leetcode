#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > target) {
                break;
            }
            if (nums[i] < target) {
                continue;
            }
            if (nums[i] == target) {
                if (start == -1) {
                    start = i;
                }
                end = i;
                continue;
            }
        }
        vector<int> result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.guessNumber(2) << endl;


    return 0;
}