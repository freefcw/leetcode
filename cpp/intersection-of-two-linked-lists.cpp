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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *pa = headA;
        ListNode *pb = headB;
        bool reachA = false;
        bool reachB = false;

        while (true)
        {
            if (pa == NULL && reachA == false)
            {
                pa = headB;
                reachA = true;
            }
            if (pb == NULL && reachB == false)
            {
                pb = headA;
                reachB = true;
            }
            if (pa == pb && pa != NULL)
            {
                return pa;
            }
            if (pa->next == NULL && pb->next == NULL && pa != pb)
            {
                return NULL;
            }

            pa = pa->next;
            pb = pb->next;
        }
    }
};

int main()
{
    Solution s;


    return 0;
}