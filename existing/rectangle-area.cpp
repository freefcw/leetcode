#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long total = this->size(A, B, C, D) + this->size(E, F, G, H);
        long interact = this->interact(A, B, C, D, E, F, G, H);

        return total - interact;
    }

    long interact(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (C <= E || D <= F || A >= G || B >= H)
        {
            return 0;
        }
        long a = max(A, E);
        long b = max(B, F);
        long c = min(C, G);
        long d = min(D, H);

        return this->size(a, b, c, d);
    }

    long size(long a, long b, long c, long d)
    {
        return abs((c - a) * (d - b));
    }
};

int main()
{
    Solution s;

    cout << s.computeArea(2) << endl;

    return 0;
}