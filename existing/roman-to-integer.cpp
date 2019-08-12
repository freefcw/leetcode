#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int current_value = 0;
        int i = 0;
        while(i < s.size())
        {
            if (i + 1 < s.size()) {
                if (s[i] == 'I') {
                    if (s[i+1] == 'V') {
                        current_value += 4;
                        i += 2;
                        continue;
                    }
                    if (s[i+1] == 'X') {
                        current_value += 9;
                        i += 2;
                        continue;
                    }
                }
                if (s[i] == 'X') {
                    if (s[i + 1] == 'L') {
                        current_value += 40;
                        i += 2;
                        continue;
                    }
                    if (s[i+1] == 'C') {
                        current_value += 90;
                        i += 2;
                        continue;
                    }
                }
                if (s[i] == 'C') {
                    if (s[i + 1] == 'D') {
                        current_value += 400;
                        i += 2;
                        continue;
                    }
                    if (s[i+1] == 'M') {
                        current_value += 900;
                        i += 2;
                        continue;
                    }
                }
            }
            // cout << s[i] << "|" << i << endl;
            int current_type = this->convert(s[i]);
            current_value += current_type;
            i++;
        }
        return current_value;
    }

    int convert(char ch) {
        if (ch == 'I') {
            return 1;
        }
        if (ch == 'V') {
            return 5;
        }
        if (ch == 'X') {
            return 10;
        }
        if (ch == 'L') {
            return 50;
        }
        if (ch == 'C') {
            return 100;
        }
        if (ch == 'D') {
            return 500;
        }
        if (ch == 'M') {
            return 1000;
        }
        return 0;
    }
};


int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}