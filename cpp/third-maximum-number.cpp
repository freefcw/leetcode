#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> maxs;
    int uniqueCount;
public:
    int thirdMax(vector<int>& nums) {
        this->maxs.resize(3);
        this->uniqueCount = 0;
        for(int i = 0; i < nums.size();i++) {
            if (this->uniqueCount < 3) {
                this->insert(nums[i]);
                continue;
            }
            if (nums[i] > this->minimal()) {
                this->insert(nums[i]);
            }
        }
        // cout << this->uniqueCount << endl;
        if (this->uniqueCount >= 3) {
            return this->maxs.back();
        }
        return this->maxs.front();
    }

    void insert(int x)
    {
        if (this->uniqueCount < 3) {
            for (int i = 0; i < this->uniqueCount; i++)
            {
                if (this->maxs[i] == x) {
                    return;
                }
                if (this->maxs[i] < x) {
                    int t = this->maxs[i];
                    this->maxs[i] = x;
                    x = t;
                }
            }
            this->uniqueCount++;
            this->maxs[this->uniqueCount-1] = x;
            return;
        }
        for (int k = 0; k < this->uniqueCount; k++)
        {
            if (x == this->maxs[k]) {
                return;
            }
            if (x > this->maxs[k])
            {
                this->uniqueCount++;
                for (int i = 2; i > k; i--)
                {
                    this->maxs[i] = this->maxs[i-1];
                }
                this->maxs[k] = x;
                return;
            }
        }
    }

    int minimal()
    {
        return this->maxs.back();
    }
};

void calc(int nums[], int x)
{
    vector<int> vn(nums, nums + x);
    Solution s;
    cout << s.thirdMax(vn) << endl;
}

int main()
{
    
    int nums[] = {1, 2, -2147483648};
    calc(nums, 3);
    
    int nums2[] = {1, 2, 3};
    calc(nums2, 3);

    int nums3[] = {1, 2};
    calc(nums3, 2);

    int nums4[] = {2};
    calc(nums4, 1);

    return 0;
}