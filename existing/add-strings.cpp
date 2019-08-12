#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;
        string n1(num1.rbegin(), num1.rend());
        string n2(num2.rbegin(), num2.rend());
        int pos = 0;
        int c1, c2;
        int carry = 0;
        while(true) {
            if (pos >= n1.size() && pos >= n2.size()) {
                break;
            }
            if (pos < n1.size()) {
                c1 = n1[pos];
            } else {
                c1 = '0';
            }
            if (pos < n2.size()) {
                c2 = n2[pos];
            } else {
                c2 = '0';
            }
            int s = this->add(c1, c2) + carry;
            carry = s / 10;
            char n = '0' + s % 10;
            result.push_back(n);
            pos++;
        }
        if (carry) {
            result.push_back('1');
        }

        return string(result.rbegin(), result.rend());
    }

    int add(char c1, char c2)
    {
        c1 = c1 - '0';
        c2 = c2 - '0';

        return c1 + c2;
    }
};

int main()
{
    Solution s;

    cout << s.addStrings("999", "999") << endl;

    return 0;
}