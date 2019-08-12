#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        s.append(1, ' ');
        for(int i = 1; i < s.size();i++) {
            if (s[i - 1] != ' ' && s[i] == ' ') {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    cout << s.countSegments("Hello, my name is John") << endl;
    cout << s.countSegments(" Hello, my name is John") << endl;
    cout << s.countSegments(" Hello,    my name is John") << endl;
    cout << s.countSegments(" Hello,    my name is John  ") << endl;
    cout << s.countSegments("i Hello,    my name is John  ") << endl;
    return 0;
}