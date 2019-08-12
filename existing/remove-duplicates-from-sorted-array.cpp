#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int pos = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != nums[pos]) {
                pos++;
                nums[pos] = nums[i];
            }
        }

        return pos + 1;
    }

};

int main()
{
    Solution s;
    std::vector<int> v;
    cout << s.removeDuplicates(v) << endl;
    v.push_back(1);
    cout << s.removeDuplicates(v) << endl;
    v.push_back(1);
    cout << s.removeDuplicates(v) << endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    cout << s.removeDuplicates(v) << endl;

    return 0;
}