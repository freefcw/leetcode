#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    while(true) {
        if (head == NULL) {
            break;
        }
        cout << head->val << endl;
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* anchor = new ListNode(-1);
        anchor->next = head;
        ListNode* current = head;
        while(current != NULL) {
            ListNode* last = current;
            current = current->next;
            if (current == NULL) {
                break;
            }
            ListNode* iIter = anchor;
            while(iIter->next != NULL) {
                if (current == iIter) {
                    break;
                }
                if (current->val < iIter->next->val) {
                    last->next = current->next;
                    ListNode* t = iIter->next;
                    iIter->next = current;
                    current->next = t;
                    current = last;
                    break;
                }
                iIter = iIter->next;
            }
        }

        return anchor->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(8);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = NULL;
    // ListNode* result = s.reverseList(head);
    head = s.insertionSortList(head);

    printList(head);

    return 0;
}