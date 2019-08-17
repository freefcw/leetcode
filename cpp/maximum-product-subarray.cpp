#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> maximum(nums.size());
        vector<int> minimum(nums.size());

        maximum[0] = nums[0];
        minimum[0] = nums[0];
        int MAX = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int max1 = nums[i] * maximum[i - 1];
            int max2 = nums[i] * minimum[i - 1];
            
            int maxit = max1 > max2 ? max1 : max2;
            int minit = max1 < max2 ? max1 : max2;

            if (maxit > nums[i]) {
                maximum[i] = maxit;
            } else {
                maximum[i] = nums[i];
            }

            if (minit < nums[i]) {
                minimum[i] = minit;
            } else {
                minimum[i] = nums[i];
            }
            if (maximum[i] > MAX) {
                MAX = maximum[i];
            }
        }
        
        return MAX;
    }
};

int main()
{
    Solution s;

    int nums[] = {-2, 0, -1, 0};
    vector<int> vn(nums, nums + 3);
    cout << s.maxProduct(vn) << endl;

    return 0;
}