#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *current = head;
        ListNode *parent = NULL;

        while(true) {
            if (current == NULL) {
                break;
            }

            if (current->val == val) {
                if (head == current) {
                    head = current->next;
                    continue;
                }
                if (parent != NULL) {
                    parent->next = current->next;
                }
            } else {
                parent = current;
            }
            current = current->next;
        }
        return head;
    }
};

ListNode *makeFront(int elemets[], int size)
{
    ListNode *head = NULL;
    ListNode *parent = NULL;

    for (int i = 0; i < size; ++i)
    {
        ListNode *node = new ListNode(elemets[i]);
        // cout << node << ':' << node->val << endl;
        if (head == NULL) {
            head = node;
        }
        if (parent == NULL) {
            parent = node;
        } else {
            parent->next = node;
            parent = node;
        }
        // cout << head << '|' << parent << endl;
    }
    return head;
}

void outlist(ListNode *head) {
    ListNode *current;
    current = head;
    cout << "-----" << endl;
    while(true) {
        if (current == NULL) {
            break;
        }
        cout << current->val << endl;
        current = current->next;
    }
}

int main()
{
    Solution s;
    ListNode *head;

    int elemets1[] = {1,2,6,3,4,5,6};
    head = makeFront(elemets1, 7);
    head = s.removeElements(head, 6);
    outlist(head);

    int elemets2[] = {6,2,6,3,4,5,6};
    head = makeFront(elemets2, 7);
    head = s.removeElements(head, 6);
    outlist(head);

    int elemets[] = {6,2,6};
    head = makeFront(elemets, 3);
    head = s.removeElements(head, 6);
    outlist(head);

    int elemets3[] = {6,6,6};
    head = makeFront(elemets3, 3);
    head = s.removeElements(head, 6);
    outlist(head);

    return 0;
}