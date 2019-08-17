#include <iostream>
#include <vector>
#include <map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
private:
    std::map<Node *, int> randomNodePoint;
    std::vector<Node*> nodes;
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return head;
        }
        auto anchor = new Node();
        auto node = anchor;
        auto originNext = head;
        int pos = 0;
        while (originNext != NULL)
        {
            if (originNext == NULL) {
                break;
            }

            node->next = new Node();
            node->next->val = originNext->val;
            node->next->next = NULL;
            node->next->random = NULL;
            this->nodes.push_back(node->next);
            
            this->randomNodePoint.insert(std::make_pair(originNext, pos));
            node = node->next;
            originNext = originNext->next;
            pos++;
        }
        originNext = head;
        node = anchor->next;
        pos = 0;
        while (originNext != NULL)
        {
            if (originNext->random != NULL) {
                auto search = this->randomNodePoint.find(originNext->random);
                if (search != this->randomNodePoint.end())
                {
                    int randomPointerIndex = search->second;
                    node->random = this->nodes[randomPointerIndex];
                }
            }
            originNext = originNext->next;
            node = node->next;
            pos++;
        }

        return anchor->next;
    }
};

int main() {
    Node* node;
    node = new(Node);
    node->val = 1;
    node->next = new(Node);
    node->random = node->next;
    node->next->val = 2;
    node->next->random = node;
    node->next->next = new(Node);
    node->next->next->val = 3;
    node->next->next->random = node;
    node->next->next->next = NULL;

    node->next->random = node->next;


    Solution s;
    Node *newNode = s.copyRandomList(node);
    while(newNode != NULL) {
        std::cout << newNode->val << std::endl;
        std::cout << newNode->next << std::endl;
        std::cout << newNode->random << std::endl;
        newNode = newNode->next;
    }
}