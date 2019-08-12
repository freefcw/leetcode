#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 1 << 30;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < min) {
                min = prices[i];
            }
            int currentProfit = prices[i] - min;
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }

        return maxProfit;
    }
};

int main()
{
    Solution s;
    int nums[] = {1 ,2, 7, 1, 5};
    vector<int> vn(nums, nums + 5);
    cout << s.maxProfit(vn) << endl;

    return 0;
}