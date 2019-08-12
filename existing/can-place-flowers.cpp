#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;


class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0) {
            return true;
        }
        if (n > flowerbed.size()) {
            return false;
        }
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n < 2)
            {
                return true;
            }

            return false;
        }
        int count = 0;
        if (flowerbed[0] == 0 && 0 == flowerbed[1])
        {
            count = 1;
            flowerbed[0] = 1;
        }
        int i = 1;
        while (i < flowerbed.size())
        {
            // cout << flowerbed[i] << "|" << i << endl;
            if (flowerbed[i] == 1) {
                i++;
                continue;
            }
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                if ((i < flowerbed.size() - 1 && flowerbed[i+1] == 0)) {
                    count++;
                    // cout << "place in " << i << endl;
                    flowerbed[i] = 1;
                }
            }
            // cout << "count" << count << endl;
            if (count >= n) {
                return true;
            }
            i++;
        }
        if (flowerbed[i - 1] == 0 && flowerbed[i - 2] == 0) {
            count++;
        }
        if (count >= n) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int nums[] = {0, 0,1,0,1};
    vector<int> vn(nums, nums + 5);
    
    cout << s.canPlaceFlowers(vn, 1) << endl;

    int nums2[] = {0, 0, 0};
    vector<int> vn2(nums2, nums2 + 3);
    
    cout << s.canPlaceFlowers(vn2, 2) << endl;

    return 0;
}