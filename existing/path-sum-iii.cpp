#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int sum;
public:
    int pathSum(TreeNode* root, int sum) {
        this->sum = sum;
        vector<int> nodes;
        return this->walk(root, &nodes);
    }

    int walk(TreeNode* root, vector<int>* nodes)
    {
        if (root == NULL) {
            return 0;
        }
        nodes->push_back(root->val);
        int count = this->clac(nodes);
        int left = this->walk(root->left, nodes);
        int right = this->walk(root->right, nodes);

        nodes->pop_back();
        return left + right + count;
    }

    int clac(vector<int>* nodes) {
        int count = 0;
        int total = nodes->size() - 1;
        int currentSum = 0;
        for (int i = total; i >= 0; --i)
        {
            currentSum += nodes->at(i);
            if (currentSum == this->sum) {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    int nums[] = {10, 5, 2, 1};
    vector<int> nodes(nums, nums+4);
    int count = 0;
    int dest = 8;
    for (int i = 0; i < nodes.size(); ++i)
    {
        int sum = nodes[i];
        for (int k = i + 1; k < nodes.size(); ++k)
        {
            sum += nodes[k];
            if (sum == dest) {
                // cout << nodes[i] << "|" << nodes[k] << endl;
                count++;
                break;
            }
        }
    }
    cout << count << endl;

    return 0;
}