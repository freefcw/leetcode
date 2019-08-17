#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int> > nodes;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (root == NULL) {
            return averages;
        }
        this->walk(root, 0);

        for (int i = 0; i < this->nodes.size(); ++i)
        {
            averages.push_back(0);
            for (int k = 0; k < this->nodes[i].size(); ++k)
            {
                averages[i] += this->nodes[i][k];
            }
            averages[i] = averages[i] / this->nodes[i].size();
        }

        return averages;
    }

    void walk(TreeNode* root, int level) {
        if (root != NULL) {
            if (this->nodes.size() <= level) {
                this->nodes.push_back(vector<int>());
            }
            this->nodes[level].push_back(root->val);
        }
        if (root->left != NULL) {
            this->walk(root->left, level + 1);
        }
        if (root->right != NULL) {
            this->walk(root->right, level + 1);
        }
    }
};


int main()
{
    Solution s;
    
    
    return 0;
}