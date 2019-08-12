#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        bool isPrime[n];
        long int i;
        for (i = 2; i < n; ++i)
        {
            isPrime[i] = true;
        }
        for (i = 2; i * i < n; ++i)
        {
            if (!isPrime[i]) {
                continue;
            }
            for (int k = i * i; k < n; k += i)
            {
                isPrime[k] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i]) {
                cout << i << endl;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    for (int i = 99; i < 100; ++i)
    {
        cout << i << ":" << s.countPrimes(i) << endl;
    }


    return 0;
}