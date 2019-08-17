#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class NumMatrix {
private:
    vector<vector<int> > sum;
public:
    NumMatrix(vector<vector<int> >& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> row(matrix[i].size());
            this->sum.push_back(row);
            for(int k = 0; k < matrix[i].size(); k++) {
                this->sum[i][k] = matrix[i][k]
                    + this->sumBase(i - 1, k) + this->sumBase(i, k - 1)
                    - this->sumBase(i -1, k - 1);
                // cout << i << ":" << k << " => " << this->sum[i][k] << endl;
            }
        }
    }

    int sumBase(int x, int y) {
        if (x < 0 || y < 0) {
            return 0;
        }
        return this->sum[x][y];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->sumBase(row2, col2)
            - this->sumBase(row1 - 1, col2) - this->sumBase(row2, col1 - 1)
            + this->sumBase(row1 - 1, col1 - 1);
    }
};

int main()
{
    vector<vector<int> > matrix;
    int nums1[] = {3, 0, 1, 4, 2};
    vector<int> vn(nums1, nums1 + 5);
    matrix.push_back(vn);
    int nums2[] = {5, 6, 3, 2, 1};
    vector<int> vn2(nums2, nums2 + 5);
    matrix.push_back(vn2);
    int nums3[] = {1, 2, 0, 1, 5};
    vector<int> vn3(nums3, nums3 + 5);
    matrix.push_back(vn3);
    int nums4[] = {4, 1, 0, 1, 7};
    vector<int> vn4(nums4, nums4 + 5);
    matrix.push_back(vn4);
    int nums5[] = {1, 0, 3, 0, 5};
    vector<int> vn5(nums5, nums5 + 5);
    matrix.push_back(vn5);
    
    
    NumMatrix s(matrix);
    cout << s.sumRegion(2, 1, 4, 3)  << endl;
    cout << s.sumRegion(1, 1, 2, 2)  << endl;
    cout << s.sumRegion(1, 2, 2, 4)  << endl;
    cout << s.sumRegion(0, 0, 2, 4)  << endl;

    return 0;
}