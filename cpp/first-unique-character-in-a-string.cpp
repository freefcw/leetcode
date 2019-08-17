#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>pos(26, 0);
        for(int i = 0;i < s.size();i++) {
            pos[(int)s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if (pos[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};


int main()
{
    Solution s;
    cout << s.firstUniqChar("leetcode") << endl;
    cout << s.firstUniqChar("loveleetcode") << endl;
    cout << s.firstUniqChar("") << endl;
    cout << s.firstUniqChar("ee") << endl;
    
    return 0;
}