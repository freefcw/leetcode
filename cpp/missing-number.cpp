#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long int sum = 0;
        long int max = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        if (nums.size() == max + 1) {
            return max + 1;
        }
        return (1 + max) * max / 2 - sum;
    }
};

int main()
{
    Solution s;
    int numbers[] = {9,6,4,2,3,5,7,0,1};
    vector<int> all(numbers, numbers+9);
    cout << s.missingNumber(all) << endl;

    return 0;
}