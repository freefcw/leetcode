
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[0] == 0) {
            digits[0] = 1;
            return digits;
        }
        int plusOne = true;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if(plusOne) {
                digits[i] = digits[i] + 1;
                plusOne = false;
            }
            if (digits[i] > 9) {
                digits[i] -= 10;
                plusOne = true;
            }
        }
        if (plusOne) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


int main()
{
    Solution s;

    int nums[] = {9,9,9};
    std::vector<int> v(nums, nums+3);
    std::vector<int> result = s.plusOne(v);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}