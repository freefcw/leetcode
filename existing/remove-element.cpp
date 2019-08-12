#include <cstdio>
#include <vector>
#include <string>
#include <cwchar>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
};

int main()
{
    Solution s;

    int ch[] = {0,1,2,2,3,0,4,2};
    vector<int> chars(ch, ch + 8);
    int ret = s.removeElement(chars, 2);
    // cout << ret << endl;
    for (int i = 0; i < ret; ++i)
    {
        cout << chars[i];// << endl;
    }


    return 0;
}