#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    int max_depth;
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        this->travel(root, 1);

        return this->max_depth;
    }

    void travel(Node* root, int depth) {
        if (root == NULL) {
            return;
        }
        if (depth > this->max_depth) {
            this->max_depth = depth;
        }
        for (int i = 0; i < root->children.size(); ++i)
        {
            this->travel(root->children[i], depth + 1);
        }
    }
};

int main()
{
    Solution s;

    return 0;
}