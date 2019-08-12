#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int n1, n2, carry = 0;
        ListNode *result, *rp;
        result = new ListNode(0);
        rp = result;
        while (true)
        {
            if (p1 == NULL && p2 == NULL)
            {
                if (carry > 0)
                {
                    ListNode *node = new ListNode(carry);
                    rp->next = node;
                }
                break;
            }
            if (p1 == NULL)
            {
                n1 = 0;
            }
            else
            {
                n1 = p1->val;
                p1 = p1->next;
            }
            if (p2 == NULL)
            {
                n2 = 0;
            }
            else
            {
                n2 = p2->val;
                p2 = p2->next;
            }

            int r = n1 + n2 + carry;
            carry = 0;
            if (r > 9)
            {
                carry = 1;
            }
            ListNode *node = new ListNode(r % 10);

            rp->next = node;
            rp = rp->next;
        }
        return result->next;
    }
};

int main()
{
    Solution s;

    cout << s.addStrings("999", "999") << endl;

    return 0;
}