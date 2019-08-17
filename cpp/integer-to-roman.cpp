#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        if (num > 999) {
            int count = num / 1000;
            result.append(count, 'M');
            num = num % 1000;
        }
        if (num >= 900) {
            result.append("CM");
            num = num % 100;
        }
        if (num > 599) {
            result.append("D");
            int count = (num - 500) / 100;
            result.append(count, 'C');
            num = num % 100;
        }
        if (num > 499) {
            result.append("D");
            num = num % 100;
        }
        if (num >= 400) {
            result.append("CD");
            num = num % 100;
        }
        if (num > 99) {
            int count = (num / 100);
            result.append(count, 'C');
            num = num % 100;
        }
        if (num > 89) {
            result.append("XC");
            num = num % 10;
        }
        if (num > 49) {
            result.append("L");
            int count = (num - 50) / 10;
            result.append(count, 'X');
            num = num % 10;
        }
        if (num > 39) {
            result.append("XL");
            num = num % 10;
        }
        if (num > 9) {
            int count = num / 10;
            result.append(count, 'X');
            num = num % 10;
        }
        if (num == 9) {
            result.append("IX");
            return result;
        }
        if (num > 5) {
            result.append("V");
            result.append((num - 5), 'I');
            return result;
        }
        if (num == 5) {
            result.append("V");
            return result;
        }
        if (num == 4) {
            result.append("IV");
            return result;
        }
        result.append(num, 'I');
        return result;

    }
};


int main()
{
    Solution s;
    cout << s.intToRoman(1) << endl;
    cout << s.intToRoman(2) << endl;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(5) << endl;
    cout << s.intToRoman(6) << endl;
    cout << s.intToRoman(7) << endl;
    cout << s.intToRoman(8) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(10) << endl;
    cout << s.intToRoman(1994) << endl;
    cout << s.intToRoman(3999) << endl;
    cout << s.intToRoman(399) << endl;
    return 0;
}