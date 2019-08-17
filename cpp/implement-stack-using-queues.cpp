#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class MyStack {
private:
    vector<int> items;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->items.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = this->items.back();
        this->items.pop_back();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return this->items.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->items.size() == 0;
    }
};


int main()
{
    Solution s;
    int nums[] = {2, 3};
    vector<int> vn(nums, nums + 2);
    cout << s.rob(vn) << endl;

    return 0;
}