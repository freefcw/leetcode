#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;
class Solution
{
public:
    string convertToTitle(int n)
    {
        string s;
        if (n < 1)
        {
            return s;
        }
        while (true)
        {
            if (n > 26)
            {
                int x = n % 26;
                s.append(1, this->toChar(x));
                n = n / 26;
                if (x == 0)
                {
                    n = n - 1;
                }
            }
            else
            {
                s.append(1, this->toChar(n));
                // cout << n << this->toChar(n) << endl;
                break;
            }
        }

        return string(s.rbegin(), s.rend());
    }

    char toChar(int n)
    {
        if (n == 0)
        {
            return 'Z';
        }
        int x = n - 1 + 'A';
        return (char)x;
    }
};
int main()
{
    Solution s;

    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(28) << endl;
    cout << s.convertToTitle(52) << endl;
    cout << s.convertToTitle(701) << endl;

    return 0;
}