#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
        vector<vector<int> > result;
        for(int i = 0; i < M.size(); i++) {
            vector<int> line(M[i].size());
            result.push_back(line);
            for(int k = 0; k < M[i].size(); k++) {
                result[i][k] = this->smooth(M, i, k);
            }
        }
        return result;
    }

    int smooth(vector<vector<int> >& M, int i, int k) {
        int sum = M[i][k];
        int count = 1;
        if (k - 1 >= 0) {
            sum += M[i][k - 1];
            count++;
        }
        if (k + 1 < M[i].size()) {
            sum += M[i][k + 1];
            count++;
        }
        if (i - 1 >= 0) {
            if (k - 1 >= 0) {
                sum += M[i - 1][k - 1];
                count++;
            }
            if (k + 1 < M[i].size()) {
                sum += M[i - 1][k + 1];
                count++;
            }
            sum += M[i - 1][k];
            count++;
        }
        if (i + 1 < M.size()) {
            if (k - 1 >= 0) {
                sum += M[i + 1][k - 1];
                count++;
            }
            if (k + 1 < M[i].size()) {
                sum += M[i + 1][k + 1];
                count++;
            }
            sum += M[i + 1][k];
            count++;
        }

        return floor((float)sum / count);
    }
};


int main()
{
    int sum = 27;
    int count = 6;
    cout << floor((float)sum / count) << endl;

    return 0;
}