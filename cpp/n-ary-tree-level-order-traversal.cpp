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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) {
            return this->nodes;
        }
        this->walk(root, 0);
        return this->nodes;
    }

    void walk(Node* root, int level) {
        if (root != NULL) {
            if (this->nodes.size() <= level) {
                this->nodes.push_back(vector<int>());
            }
            this->nodes[level].push_back(root->val);
        }
        for (int i = 0; i < root->children.size(); ++i)
        {
            this->walk(root->children[i], level + 1);
        }
    }
};

int main()
{
    Solution s;

    return 0;
}