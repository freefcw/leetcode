#include <iostream>
#include <vector>
#include <map>
#include "graph.h"

class Solution
{
private:
    std::map<Node *, Node *> oldNode2NewNode;
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL) {
            return node;
        }
        Node *newNode = this->duplicateNode(node);
        walk(newNode, node);

        return newNode;
    }

    void walk(Node *newNode, Node *oldNode)
    {
        for (int i = 0; i < oldNode->neighbors.size(); i++)
        {
            Node *nNode = this->findNewNode(oldNode->neighbors[i]);
            // std::cout << "current: " << newNode->val;
            // std::cout << " neighbors: " << oldNode->neighbors[i]->val << std::endl;
            bool hasVisited = true;
            if (nNode == NULL) {
                hasVisited = false;
                nNode = this->duplicateNode(oldNode->neighbors[i]);
            }
            newNode->neighbors.push_back(nNode);
            if (!hasVisited) {
                walk(nNode, oldNode->neighbors[i]);
            }
        }
        
    }

    Node *duplicateNode(Node *from)
    {
        Node *newNode = new Node();
        std::vector<Node *> _emptyNeighbours;
        newNode = new Node();
        newNode->val = from->val;
        newNode->neighbors = _emptyNeighbours;

        this->oldNode2NewNode.insert(std::make_pair(from, newNode));

        return newNode;
    }

    Node * findNewNode(Node *node)
    {
        auto search = this->oldNode2NewNode.find(node);
        if (search != this->oldNode2NewNode.end())
        {
            return search->second;
        }
        return NULL;
    }
};

int main() {
    Node *node = new Node();
    node->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    node->neighbors.push_back(node2);
    node->neighbors.push_back(node3);

    node2->neighbors.push_back(node);
    node2->neighbors.push_back(node4);

    node3->neighbors.push_back(node);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node2);
    node4->neighbors.push_back(node3);

    Solution s;
    Node *newNode = s.cloneGraph(node);
    


        return 0;
}