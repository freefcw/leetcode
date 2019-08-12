
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row1(rowIndex + 1, 1);
        vector<int> row2(rowIndex + 1, 1);
        if (rowIndex == 0) {
            return row1;
        }

        vector<int> *p1;
        vector<int> *p2;
        for (int i = 1; i < rowIndex + 1; ++i)
        {
            if (i % 2 == 0) {
                p1 = &row1;
                p2 = &row2;
            } else {
                p1 = &row2;
                p2 = &row1;
            }
            for (int k = 1; k < i; ++k)
            {
                cout << i << "|" << k << endl;
                if (k > 0 && k < i) {
                    (*p2)[k] = (*p1).at(k-1) + (*p1).at(k);
                    continue;
                }
                (*p2)[k] = 1;
            }
        }

        return *p2;
    }
};

int main()
{
    Solution s;
    int rows = 4;
    vector<int> result = s.getRow(rows);

    for (int k = 0; k < result.size(); ++k)
    {
        cout << result.at(k) << ",";
    }
    cout << endl;

    return 0;
}