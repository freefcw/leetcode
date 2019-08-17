
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result(numRows);
        if (numRows == 0) {
            return result;
        }
        result[0].resize(1);
        result[0][0] = 1;

        for (int i = 1; i < numRows; ++i)
        {
            result[i].resize(i + 1);

            for (int k = 0; k < i+1; ++k)
            {
                if (k - 1 > 0 && k < i) {
                    // cout << i << ':' << k << " =>" << result[i-1][k] << "|" << result[i-1][k]<< endl;
                    result[i][k] = result.at(i-1).at(k - 1) + result.at(i-1).at(k);
                    continue;
                }
                result[i][k] = 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    int rows = 21;
    vector<vector<int> > result = s.generate(rows);
    for (int i = 0; i < rows; ++i)
    {
        for (int k = 0; k < i + 1; ++k)
        {
            cout << result[i][k] << ',';
        }
        cout << endl;
    }

    return 0;
}