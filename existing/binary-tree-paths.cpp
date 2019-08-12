#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <strstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
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
            this->output(nodes);
            nodes->pop_back();
            return;
        }
        this->walk(root->left, nodes);
        this->walk(root->right, nodes);

        nodes->pop_back();
    }

    void output(vector<int>* nodes) {
        string concats;
        char buff[10];
        for (int i = 0; i < nodes->size(); ++i)
        {
            if (i != 0) {
                concats += "->";
            }
            memset(buff, 0, sizeof(buff));
            sprintf(buff, "%d", nodes->at(i));
            concats += buff;
        }
        this->result.push_back(concats);
    }
};

int main()
{
    Solution s;
   

    return 0;
}