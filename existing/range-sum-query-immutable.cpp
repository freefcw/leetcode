#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class NumArray {
private:
    vector<int> nums;
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        if (nums.size() == 0) {
            return;
        }
        this->sums.resize(nums.size());
        this->sums[0] = 0;
        for(int i = 1; i < nums.size(); i++) {
            this->sums[i] = this->sums[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int x, int y) {
        return this->sums[y] - this->sums[x] + this->nums[y];
    }
};

class NumArray2 {
private:
    vector<int> nums;
public:
    NumArray2(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int p = i; p <= j; p++) {
            sum += this->nums[p];
        }
        return sum;
    }
};


int main()
{
    int nums[] = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};
    vector<int> vn(nums, nums + 13);
    NumArray s(vn);
    cout << s.sumRange(0, 9)  << endl;
    cout << s.sumRange(0, 12)  << endl;
    // cout << s.sumRange(2, 5)  << endl;
    // cout << s.sumRange(0, 5)  << endl;
    return 0;
}