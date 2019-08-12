#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        int top = -1;
        int left = -1;
        int button = matrix.size();
        int right = matrix[0].size();
        int x = 0;
        int y = 0;
        int direction_x = 0;
        int direction_y = 1;
        while(true) {
            // cout << x << ":" << y << endl;
            result.push_back(matrix[x][y]);
            x = x + direction_x;
            y = y + direction_y;
            if (x == top) {
                left++;
                x = top + 1;
                direction_x = 0;
                direction_y = 1;
                y = y + direction_y;
            }
            if (x == button) {
                right--;
                x = button - 1;
                direction_x = 0;
                direction_y = -1;
                y = y + direction_y;
            }
            if (y == right) {
                top++;
                y = right - 1;
                direction_x = 1;
                direction_y = 0;
                x = x + direction_x;
            }
            if (y == left) {
                button--;
                y = left + 1;
                direction_x = -1;
                direction_y = 0;
                x = x + direction_x;
            }
            if (top == button - 1 || left == right - 1) {
                break;
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(1);
    line1.push_back(2);
    line1.push_back(3);
    line1.push_back(4);
    matrix.push_back(line1);
    vector<int> line2;
    line2.push_back(5);
    line2.push_back(6);
    line2.push_back(7);
    line2.push_back(8);
    matrix.push_back(line2);
    vector<int> line3;
    line3.push_back(9);
    line3.push_back(10);
    line3.push_back(11);
    line3.push_back(12);
    matrix.push_back(line3);
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}