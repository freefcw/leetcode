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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head->next;
        head->next = NULL;
        ListNode* next = NULL; 
        while(true) {
            if (current == NULL) {
                return head;
            }
            next = current->next;
            current->next = head;
            head = current;
            current = next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* anchor = new ListNode(-1);
        anchor->next = head;
        ListNode* current = anchor;
        int pos = 1;
        ListNode* from;
        ListNode* to;

        while(true) {
            if (pos == m) {
                from = current;
            }
            if (pos == n + 1) {
                to = current;
                break;
            }
            current = current->next;
            pos++;
        }
        ListNode* tailHead = to->next;
        to->next = NULL;
        ListNode* reverseTail = from->next;
        from->next = this->reverseList(from->next);
        reverseTail->next = tailHead;

        return anchor->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = NULL;
    // ListNode* result = s.reverseList(head);
    ListNode* result = s.reverseBetween(head, 1, 4);
    printList(result);

    return 0;
}