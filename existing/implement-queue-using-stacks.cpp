#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;


class MyQueue {
private:
    vector<int> stack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        this->stack.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ele = this->stack.front();
        this->stack = vector<int>(this->stack.begin() + 1, this->stack.end());
        return ele;
    }
    
    /** Get the front element. */
    int peek() {
        return this->stack.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->stack.size() == 0;
    }
};



int main()
{
    Solution s;
    s.sortedListToBST();
    
    return 0;
}