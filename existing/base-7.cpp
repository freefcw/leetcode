#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0) {
            return "0";
        }
        int flag = 1;
        if (num < 0) {
            flag = -1;
            num = -1 * num;
        }
        vector<int> nums;
        while(num > 0) {
            nums.push_back(num % 7);
            num = num / 7;
        }
        string result;
        if (flag == -1) {
            result.push_back('-');
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result.push_back(nums[i] + '0');
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.convertToBase7(101) << endl;
    cout << s.convertToBase7(-6) << endl;
    cout << s.convertToBase7(-7) << endl;
    cout << s.convertToBase7(7) << endl;
    cout << s.convertToBase7(10000000) << endl;
    cout << s.convertToBase7(-10000000) << endl;
    cout << s.convertToBase7(0) << endl;
    cout << s.convertToBase7(1) << endl;
    cout << s.convertToBase7(-1) << endl;
    return 0;
}