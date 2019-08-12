#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution
{
private:
    string res;
public:
    string tree2str(TreeNode *t)
    {
        if (t == NULL) {
            return "";
        }
        string current = this->value2str(t->val);

        string left;
        if (t->left) {
            left = this->tree2str(t->left);
        }
        string right;
        if (t->right) {
            right = this->tree2str(t->right);
        }
        if (left.size()) {
            current = current + "(" + left + ")";
        }
        if (right.size()) {
            if (left.size() == 0) {
                current = current + "()";
            }
            current = current + "(" + right + ")";
        }

        return current;
    }

    string value2str(int x)
    {
        char buff[20];
        sprintf(buff, "%d", x);
        return string(buff);
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << s.tree2str(root) << endl;

    return 0;
}