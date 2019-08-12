
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *slow;
        ListNode *fast;
        slow = head;
        fast = head->next;
        while(slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            if (fast->next == slow) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

/**
    自己做cache
*/
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        vector<ListNode *> sentinels;
        ListNode *current;
        current = head;
        while(true) {
            if (current == NULL) {
                return false;
            }
            // cout << "loop:" << current << endl;
            for (std::vector<ListNode *>::iterator node = sentinels.begin(); node != sentinels.end(); ++node)
            {
                if (*node == NULL) {
                    break;
                }
                // cout << "sentinel:" << *node << endl;
                if (*node == current) {
                    return true;
                }
            }
            sentinels.push_back(current);
            current = current->next;
        }
        return false;
    }
};

ListNode* buildList(int nums[], int total, int pos)
{
    ListNode *posNode;
    ListNode *head;
    if (total == 0) {
        return head;
    }
    head = new ListNode(nums[0]);
    if (pos == 0) {
        head->next = head;
        return head;
    }
    ListNode *current;
    current = head;
    for (int i = 1; i < total; ++i)
    {
        current->next = new ListNode(nums[i]);
        // cout << current << ":" << current->val << endl;
        if (i == pos) {
            posNode = current->next;
        }
        current = current->next;
    }
    current->next = posNode;

    return head;
}

int main()
{
    Solution s;
    int nums[] = {1,2,3,4,5};
    ListNode *head = buildList(nums, 5, 4);
    // int count = 0;
    // while(true) {
    //     count++;
    //     if (count > 10) {
    //         break;
    //     }
    //     cout << head->val << endl;
    //     head = head->next;
    // }

    cout << s.hasCycle(head) << endl;


    return 0;
}