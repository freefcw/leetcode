#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
        if (n == 0) {
            return matrix;
        }
        for(int i = 0; i < n; i++) {
            vector<int> line(n);
            matrix.push_back(line);
        }
        int top = -1;
        int left = -1;
        int button = n;
        int right = n;
        int x = 0;
        int y = 0;
        int direction_x = 0;
        int direction_y = 1;
        int index = 1;
        while(true) {
            // cout << x << ":" << y << endl;
            matrix[x][y] = index;
            index++;
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
        return matrix;
    }
};

int main()
{
    Solution s;
    int size = 5;
    vector<vector<int> > matrix = s.generateMatrix(size);
    
    for(int i = 0; i < size; i++) {
        for(int k = 0; k < size; k++) {
            cout << matrix[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}