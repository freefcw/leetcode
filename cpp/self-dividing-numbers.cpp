#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> results;
        for(int i = left; i <= right; i++) {
            if (this->canDividing(i)) {
                results.push_back(i);
            }
        }
        return results;
    }

    bool canDividing(int num) {
        int x = num;
        while(x > 0) {
            int left = x % 10;
            if (left == 0) {
                return false;
            }
            if (num % left != 0) {
                return false;
            }
            x = x / 10;
        }
        return true;
    }
};

int main()
{
    Solution s;
    // for(int i = 5; i < 200; i ++) {
    //     if (s.canDividing(i)) {
    //         cout << i << endl;
    //     }
    // }
    vector<int> ret = s.selfDividingNumbers(1, 22);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }
    
    
    return 0;
}