#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int totalProfit = 0;
        int currentMin = 1 << 30;
        prices.push_back(0);
        for (int i = 0; i < prices.size(); ++i)
        {
            if (currentMin > prices[i]) {
                currentMin = prices[i];
            }
            // cout << "current: " << prices[i] << endl;
            if (prices[i+1] - prices[i] > 0) {
                continue;
            }
            if (prices[i+1] - prices[i] < 0) {
                int currentProfit =  prices[i] - currentMin;
                if (currentProfit > 0) {
                    totalProfit += currentProfit;
                }
                // cout << "|" << currentProfit << "|" << totalProfit << endl;
                currentMin = prices[i+1];
            }
        }

        return totalProfit;
    }
};

int main()
{
    Solution s;
    int nums[] = {7,8,9};
    vector<int> vn();
    cout << s.maxProfit(vn) << endl;

    return 0;
}