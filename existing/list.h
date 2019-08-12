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
        cout << head->val << "=>";
        head = head->next;
    }
    cout << endl;
}