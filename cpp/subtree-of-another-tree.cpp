#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == t && s == NULL) {
            return true;
        }
        if (s == NULL || t == NULL) {
            return false;
        }
        if (this->isSameTree(s, t)) {
            return true;
        }
        if (this->isSubtree(s->left, t)) {
            return true;
        }
        if (this->isSameTree(s->right, t)) {
            return true;
        }
        if (this->isSubtree(s->right, t)) {
            return true;
        }

        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q && p == NULL) {
            return true;
        }
        if (p == NULL || q == NULL && p != q) {
            return false;
        }
        if (p->val !=  q->val) {
            return false;
        }
        if (!this->isSameTree(p->left, q->left)){
            return false;
        }
        if (!this->isSameTree(p->right, q->right)) {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;

    return 0;
}