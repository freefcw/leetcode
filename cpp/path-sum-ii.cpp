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

class Solution {
private:
    int sum;
    vector<vector<int> > result;
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        this->sum = sum;
        vector<int> nodes;
        this->walk(root, &nodes);

        return this->result;
    }

    void walk(TreeNode* root, vector<int>* nodes)
    {
        if (root == NULL) {
            return;
        }
        nodes->push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            this->clac(nodes);
            nodes->pop_back();
            return;
        }
        this->walk(root->left, nodes);
        this->walk(root->right, nodes);

        nodes->pop_back();
    }

    void clac(vector<int>* nodes) {
        int count = 0;
        int currentSum = 0;
        for (int i = 0; i < nodes->size(); ++i)
        {
            currentSum += nodes->at(i);
        }
        if (currentSum == this->sum) {
            vector<int> nv(nodes->begin(), nodes->end());
            this->result.push_back(nv);
        }
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