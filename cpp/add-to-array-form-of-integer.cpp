#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        vector<int> a(A.rbegin(), A.rend());
        vector<int> b;
        while (true)
        {
            if (K < 10)
            {
                b.push_back(K);
                break;
            }
            b.push_back(K % 10);
            K = K / 10;
        }

        return this->addArray(a, b);
    }

    vector<int> addArray(vector<int> &a, vector<int> &b)
    {
        vector<int> result;
        int pos = 0;
        int carry = 0;
        while (true)
        {
            if (pos >= a.size() && pos >= b.size()) {
                if (carry > 0) {
                    result.push_back(carry);
                }
                break;
            }
            int a1 = 0;
            int b1 = 0;
            if (pos < a.size()) {
                a1 = a[pos];
            }
            if (pos < b.size()) {
                b1 = b[pos];
            }
            int n = a1 + b1 + carry;
            result.push_back(n % 10);
            carry = 0;
            if (n > 9) {
                carry = 1;
            }
            pos++;
        }

        vector<int> r2(result.rbegin(), result.rend());
        return r2;
    }
};

int main()
{
    Solution s;
    int nums[] = {0};
    vector<int> vn(nums, nums + 1);

    vector<int> r2 = s.addToArrayForm(vn, 0);
    cout << "------" << endl;
    for (int i = 0; i < r2.size(); i++)
    {
        cout << r2[i] << endl;
    }
    

    return 0;
}