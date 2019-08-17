#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        if (N == 0) return true;
        if (N == 1) return false;

        return !this->divisorGame(N - 1);
    }
};

int main()
{
    Solution s;
    s.divisorGame(4);

    return 0;
}