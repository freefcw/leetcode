#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;

    Node() {}

    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};