#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;


class MyHashSet {
private:
    int bits[32000];
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(this->bits, 0, sizeof(bits));
    }
    
    void add(int key) {
        int pos = key / 32;
        int n = key % 32;
        this->bits[pos] = this->bits[pos] | (1 << n);
    }
    
    void remove(int key) {
        int pos = key / 32;
        int n = key % 32;
        if (this->contains(key)) {
            this->bits[pos] = this->bits[pos] ^ (1 << n);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = key / 32;
        int n = key % 32;
        return this->bits[pos] & (1 << n);
    }
};

int main()
{
    MyHashSet* hashSet = new MyHashSet();
    
    for(int i = 0; i <= 100; i++) {
        hashSet->add(i);
        cout << hashSet->contains(i) << endl;
    }
    hashSet->remove(50);
    hashSet->remove(50);
    cout << hashSet->contains(50) << endl;
    cout << hashSet->contains(50) << endl;
    // hashSet->add(1);         
    // hashSet->add(2);         
    // cout << hashSet->contains(1) << endl;    // returns true
    // hashSet.contains(3);    // returns false (not found)
    // hashSet.add(2);          
    // hashSet.contains(2);    // returns true
    // hashSet.remove(2);          
    // hashSet.contains(2);    // returns false (already removed)

    return 0;
}