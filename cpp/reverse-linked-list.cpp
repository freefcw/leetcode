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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *back;
        ListNode *current;
        ListNode *walk;
        walk = head;
        back = NULL;
        while(true) {
            current = walk;
            walk = walk->next;
            current->next = back;
            back = current;
            if (walk == NULL) {
                break;
            }
        }
        return back;
    }
};

void output_list(ListNode *head) {
    ListNode *node = head;
    while(node!=NULL) {
        cout << "back2:" << node->val << endl;
        node = node->next;
    }
}

int main()
{
    Solution s;
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);

    head = s.reverseList(head);
    output_list(head);
    return 0;
}