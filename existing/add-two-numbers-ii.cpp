#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int carry;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> r1 = this->flat(l1);
        vector<int> r2 = this->flat(l2);
        vector<int> r3 = this->doAdd(r1, r2);
        ListNode *result = new ListNode(0);
        ListNode *node = result;
        for(int i = r3.size() - 1; i >= 0; i--) {
            node->next = new ListNode(r3[i]);
            node = node->next;
        }
        return result->next;
    }

    void outputVector(vector<int>& v) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
        cout << "-----" << endl;
    }

    vector<int> flat(ListNode* node) {
        vector<int> t;
        while(node != NULL) {
            t.push_back(node->val);
            node = node->next;
        }
        vector<int> t2(t.rbegin(), t.rend());
        return t2;
    }

    vector<int> doAdd(vector<int>& r1, vector<int>& r2) {
        int pos = 0;
        int carry = 0;
        vector<int> r3;
        while(true) {
            if (pos >= r1.size() && pos >= r2.size()) {
                if (carry > 0) {
                    r3.push_back(carry);
                }
                break;
            }
            int a = 0;
            if (pos < r1.size()) {
                a = r1[pos];
            }
            int b = 0;
            if (pos < r2.size()) {
                b = r2[pos];
            }
            int c = a + b + carry;
            carry = 0;
            if (c > 9) {
                carry = 1;
            }
            r3.push_back(c % 10);
            pos++;
        }
        return r3;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;


    return 0;
}