#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include "leetcode/tree.h"

using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        this->sumTree(root, 0);

        int sum = 0;
        for(int i = 0; i < this->nums.size();i++) {
            sum += this->nums[i];
        }

        return sum;
    }

    void sumTree(TreeNode* root, int parent)
    {
        int current = parent * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            this->nums.push_back(current);
        }

        if (root->left != NULL) {
            this->sumTree(root->left, current);
        }
        if (root->right != NULL) {
            this->sumTree(root->right, current);
        }
    }
};

int main()
{
    
    return 0;
}