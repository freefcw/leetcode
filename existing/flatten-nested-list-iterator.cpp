#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
private:
    int val;
    vector<NestedInteger> vals;
    bool isInt;
  public:
    NestedInteger() {
        this->val = 0;
        this->isInt = false;
    }
    void setInteger(int val) {
        this->val = val;
        this->isInt = true;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return this->isInt;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        if (this->isInt) {
            return this->val;
        }
        return -1;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList()
    {
        return this->vals;
    }
};

class NestedIterator {
private:
    stack<NestedInteger> myStack;

    void appendList(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            if (nestedList[i].isInteger()) {
                this->myStack.push(nestedList[i]);
            } else {
                this->appendList(nestedList[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->appendList(nestedList);
    }

    int next() {
        NestedInteger item = this->myStack.top();
        this->myStack.pop();
        if (!item.isInteger()) {
            vector<NestedInteger> contents = item.getList();
            this->appendList(contents);
            return this->next();
        }
        return item.getInteger();
    }

    bool hasNext() {
        return this->myStack.size() > 0;
    }
};

int main() {
    vector<NestedInteger> nestedList;
    NestedInteger item;
    item.setInteger(1);
        NestedInteger item2;
    item2.setInteger(2);
    nestedList.push_back(item);
    nestedList.push_back(item2);
    // cout << item.getInteger() << endl;

    NestedIterator i(nestedList);
    while(i.hasNext()) {
        cout << i.next() << endl;
    }
}