#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<int> cache(31);
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            cache[i] = cache[i-1] + cache[i-2];
        }
        return cache[n];
    }
};


class Solution2 {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        return this->fib(n - 1) + this->fib(n - 2);
    }
};

int main()
{
    Solution s;
    cout << s.fib(4) << endl;

    return 0;
}