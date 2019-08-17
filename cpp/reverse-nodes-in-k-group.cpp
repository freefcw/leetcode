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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }
        ListNode* current = head;
        ListNode* anchor = new ListNode(-1);
        ListNode* tail = anchor;
        anchor->next = head;
        int pos = 1;
        while(true) {
            if (current == NULL) {
                return anchor->next;
            }
            // cout << pos << ":" << current->val << endl;
            if (pos % k == 0) {
                ListNode* nextHead = current->next;
                current->next = NULL;
                ListNode* currentHead = tail->next;
                tail->next = this->reverseList(currentHead);
                tail = currentHead;
                tail->next = nextHead;
                current = nextHead;
            } else {
                current = current->next;
            }

            pos++;
        }
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
    ListNode* result = s.reverseKGroup(head, 6);
    printList(result);

    return 0;
}