#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1 = this->convertInt(num1);
        vector<int> n2 = this->convertInt(num2);
        // this->output(n1);
        // this->output(n2);
        vector<int> result(n1.size() + n2.size(), 0);
        // this->output(result);
        for(int i = 0; i < n1.size(); i++) {
            vector<int> temp(result.size(), 0);
            for(int k = 0; k < n2.size(); k++) {
                temp[i+k] = n2[k] * n1[i];
            }
            this->addArray(result, temp);
        }
        // this->output(result);
        string k;
        bool leadZero = true;
        for(int i = result.size() - 1; i >= 0; i--) {
            if (result[i] == 0 && leadZero) {
                continue;
            }
            if (result[i] != 0) {
                leadZero = false;
            }
            k.append(1, (char)(result[i] + '0'));
        }
        if (k.size() == 0) {
            k = "0";
        }
        return k;
    }

    void addArray(vector<int>& result, vector<int>& t) {
        int carry = 0;
        for(int i = 0; i < result.size();i++) {
            result[i] = result[i] + t[i] + carry;
            if (result[i] > 9) {
                carry = result[i] / 10;
                result[i] = result[i] % 10;
            } else {
                carry = 0;
            }
        }
        if (carry > 0) {
            result.push_back(carry);
        }
    }

    void output(vector<int>& v) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << ':';
        }
        cout << endl;
    }

    vector<int> convertInt(string num1) {
        vector<int> n;
        for(int i = num1.size() - 1; i >= 0; i--) {
            n.push_back((int)(num1[i] - '0'));
        }
        return n;
    }
};


int main()
{
    Solution s;
    cout << s.multiply("123", "456") << endl;
    cout << s.multiply("0", "456") << endl;
    cout << s.multiply("0", "0") << endl;
    cout << s.multiply("1", "1") << endl;
    cout << s.multiply("2", "3") << endl;

    return 0;
}