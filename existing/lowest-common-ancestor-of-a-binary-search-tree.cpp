#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        
        if ((p->val < root->val) && (q->val < root->val)) {
            return this->lowestCommonAncestor(root->left, p, q);
        }

        if ((p->val > root->val) && (q->val > root->val)) {
            return this->lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

int main()
{
    Solution s;
    s.lowestCommonAncestor()
    
    return 0;
}