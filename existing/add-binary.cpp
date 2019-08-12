#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        this->flip(a);
        this->flip(b);
        string result;
        if (a.size() > b.size()) {
            result.resize(a.size() + 1, '0');
        } else {
            result.resize(b.size() + 1, '0');
        }

        int index = 0;

        while(index < result.size()) {
            int a1 =0, b1 = 0;
            if (index < a.size()) {
                a1 = a[index] - 0x30;
            }
            if (index < b.size()) {
                b1 = b[index] - 0x30;
            }
            // cout << a1 << '|' << b1 << ':' << result << endl;

            if (a1 + b1 == 2) {
                result[index+1] = '1';
            }
            if(a1 + b1 == 1) {
                if (result[index] == '1') {
                    result[index+1] = '1';
                    result[index] = '0';
                } else {
                    result[index] = '1';
                }
            }

            index++;
        }
        if (result.size() > 1 && result[result.size() - 1] == '0') {
            result.resize(result.size() - 1);
        }
        // cout << result << '|' << result[0] - 0x30 << ':' << result.size() << endl;
        this->flip(result);
        // cout << result << '|' << result[0] - 0x30 << ':' << result.size() << endl;
        return result;
    }

    void flip(string& a) {
        if (a.size() == 1) {
            return;
        }
        int i = 0,j = 0;
        char ch;
        int length = a.size();
        while(true) {
            j = length - i - 1;
            // cout << i << '|' << j << endl;
            if (i >= j) {
                break;
            }
            ch = a[i];
            a[i] = a[j];
            a[j] = ch;
            i++;
        }
    }
};

int main()
{
    Solution s;
    // cout << s.flip("0") << endl;
    cout << s.addBinary("0", "0") << endl;
    cout << s.addBinary("1", "0") << endl;
    cout << s.addBinary("11", "0") << endl;
    cout << s.addBinary("11", "100") << endl;
    cout << s.addBinary("11", "1") << endl;
    cout << s.addBinary("1010", "1011") << endl;


    return 0;
}