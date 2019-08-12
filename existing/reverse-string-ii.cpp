#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int destPos = s.size() - s.size() % (k * 2);
        string result;
        
        for(int i = 0; i < destPos; i = i + k * 2) {
            string buff;
            for(int k1 = 1; k1 <= k; k1++) {
                buff.push_back(s[i + k - k1]);
            }
            result.append(buff);
            for(int k1 = 0; k1 < k; k1++) {
                result.push_back(s[i + k + k1]);
            }
        }
        int left = s.size() - destPos;
        int target = k;
        if (left <= k) {
            target = left;
        }
        string buff;
        for(int i = target - 1; i >= 0; i--) {
            buff.push_back(s[destPos + i]);
        }
        result.append(buff);
        if (left > k) {
            int i = 0;
            while(true) {
                if (destPos + k + i >= s.size()) {
                    break;
                }
                result.push_back(s[destPos + k + i]);
                i++;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout << s.reverseStr("ab", 2) << endl;
    
    return 0;
}