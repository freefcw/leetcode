#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int counts_a = 0;
        int counts_l = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                counts_l++;
            } else {
                counts_l = 0;
            }
            if (s[i] == 'A') {
                counts_a++;
            }
            if (counts_a > 1 || counts_l > 2) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;
    cout << s.checkRecord("PPALPPP") << endl;
    cout << s.checkRecord("AALPPP") << endl;
    cout << s.checkRecord("LALL") << endl;
    cout << s.checkRecord("LALLL") << endl;
    
    return 0;
}