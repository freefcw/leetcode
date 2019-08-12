#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;



class MinStack {
public:
    vector<int> items;
    vector<int> currentMin;
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        this->items.push_back(x);
        if (this->currentMin.size() == 0) {
            this->currentMin.push_back(x);
        } else {
            int min = this->currentMin[this->currentMin.size() - 1];
            if (min < x) {
                this->currentMin.push_back(min);
            } else {
                this->currentMin.push_back(x);
            }
        }
        // cout << this->items.back() << ":" << this->currentMin.back() << endl;
    }

    void pop() {
        if (this->items.size() > 0) {
            this->items.pop_back();
            this->currentMin.pop_back();
        }
    }

    int top() {
        return this->items.back();
    }

    int getMin() {
        return this->currentMin.back();
    }
};


int main()
{
    MinStack* minStack = new MinStack();
    // minStack->push(-2);
    // minStack->push(0);
    // minStack->push(-3);
    // cout << endl << minStack->getMin();
    minStack->pop();
    cout << endl << minStack->top();
    // cout << endl << minStack->getMin();

    return 0;
}