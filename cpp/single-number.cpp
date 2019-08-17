#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            sum = sum ^ nums[i];
        }

        return sum;
    }
};

int main()
{
    Solution s;
    int numbers[] = {3, 2, 2};
    vector<int> all(numbers, numbers+3);
    cout << s.singleNumber(all) << endl;

    return 0;
}