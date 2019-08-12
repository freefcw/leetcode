#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n < 10) {
            return n;
        }
        vector<long int> counts;
        long int d = 9;
        for (int i = 0; i < 10; i++)
        {
            // cout << d * (i + 1) << "i" << i + 1 << endl;
            counts.push_back(d * (i + 1));
            d = d * 10;
        }
        int bita = 0;
        while (counts[bita] < n)
        {
            n = n - counts[bita];
            bita++;
        }
        bita++;
        // cout << n << "bita:" << bita << endl;

        int add_count = n / bita;
        int pos = n % bita;
        if (pos == 0)
        {
            add_count--;
        }
        int number = add_count + pow(10, bita - 1);
        // cout << number << 'c' << pos << endl;
        return this->getNumN(number, pos);
    }

    int getNumN(int x, int i)
    {
        vector<int> bits;
        while (x)
        {
            bits.push_back(x % 10);
            x = x / 10;
        }
        if (i == 0)
        {
            return bits.front();
        }
        return bits[bits.size() - i];
    }
};

int main()
{
    Solution s;

    cout << s.findNthDigit(3999) << endl;

    return 0;
}