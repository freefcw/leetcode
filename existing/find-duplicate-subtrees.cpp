#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include "leetcode/tree.h"

using namespace std;

class Solution {
private:
    map<string, int> nodeMap;
    vector<TreeNode*> result;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        this->generateNode(root);
        return this->result;
    }
    string generateNode(TreeNode* node) {
        if (node == NULL) {
            return "#";
        }
        string current("#");
        current.append(1, '0' + node->val);
        current.append(this->generateNode(node->left));
        current.append(this->generateNode(node->right));

        if (this->addRecord(current)) {
            this->result.push_back(node);
        }

        return current;
    }

    bool addRecord(string record)
    {
        map<string, int>::iterator iter = this->nodeMap.find(record);
        if (iter == this->nodeMap.end()) {
            this->nodeMap[record] = 1;
            return false;
        }
        
        this->nodeMap[record] = this->nodeMap[record] + 1;
        if (this->nodeMap[record] == 2) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    vector<TreeNode*> nodes = s.findDuplicateSubtrees(root);
    for(int i = 0; i < nodes.size(); i++) {
        cout << nodes[i]->val << endl;
    }
    
    return 0;
}