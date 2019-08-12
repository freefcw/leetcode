#include <cstdio>
#include <vector>
#include <iostream>
#include <list-node>

using namespace std;


// https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        ListNode *current;
        int total = 0;
        current = head;
        while(current != NULL) {
            total++;
            current = current->next;
        }
        int count = 0;
        ListNode *back = head;
        ListNode *next = NULL;
        current = head;
        while(current != NULL) {
            count++;
            if (count * 2 <= total) {
                next = current->next;
                current->next = back;
                if (count == 1) {
                    // head no next
                    back->next = NULL;
                }
                back = current;
                current = next;

                continue;
            }
            if (count * 2 - 1 == total) {
                current = current->next;
                continue;
            }
            if (count * 2 > total) {
                // cout << "count:" << count
                //     << "[" << current->val << "|" << back->val << "]"
                //     << endl;
                // cout << current->val <<endl;
                // cout << back->val <<endl;
                if (current->val != back->val) {
                    return false;
                }
                current = current->next;
                back = back->next;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);

    cout << s.isPalindrome(head) << endl;


    return 0;
}