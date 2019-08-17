#include <iostream>
#include <map>
#include <vector>

using namespace std;

class CacheItem {
public:
    int key;
    int data;
    CacheItem *prev;
    CacheItem *next;
};

class LRUCache {
private:
    map<int, CacheItem*> dataStore;
    CacheItem *head;
    CacheItem *tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = NULL;
        this->tail = NULL;
    }
    
    int get(int key) {
        // cout << "key " << key << endl;
        // this->output("get");
        if (this->capacity == 0) {
            return -1;
        }
        map<int, CacheItem*>::iterator iter = this->dataStore.find(key);

        if (iter == this->dataStore.end()) {
            return -1;
        }

        CacheItem *item = this->dataStore[key];
        
        if (item != this->head) {
            if (this->tail == item) {
                this->tail = item->prev;
                this->tail->next = NULL;
            } else {
                item->prev->next = item->next;
                item->next->prev = item->prev;
            }
            
            this->head->prev = item;
            item->next = this->head;
            item->prev = NULL;
            this->head = item;
        }

        return item->data;
    }
    
    void put(int key, int value) {
        if (this->capacity == 0) {
            return;
        }
        int actual = this->get(key);
        if (actual != -1) {
            this->dataStore[key]->data = value;
            return;
        }
        // cout << "PUT" << value << endl;
        this->checkCapacity();
        CacheItem *item = new CacheItem();
        item->key = key;
        item->data = value;

        if (this->tail == NULL) {
            this->head = item;
            item->prev = NULL;
            item->next = NULL;
            this->tail = item;
        } else {
            this->head->prev = item;
            item->prev = NULL;
            item->next = this->head;
            this->head = item;
            // cout << "HEAD " << this->head->data << endl;
        }
        
        this->dataStore[key] = item;
    }

    void checkCapacity()
    {
        // this->output("cc");
        if (this->dataStore.size() >= this->capacity) {
            CacheItem* last = this->tail;
            if (this->tail == this->head) {
                this->head = NULL;
                this->tail = NULL;
                this->dataStore.clear();
            } else {
                this->tail = this->tail->prev;
                this->tail->next = NULL;
                map<int, CacheItem*>::iterator iter = this->dataStore.find(last->key);
                this->dataStore.erase(iter);
            }
            
            if (last != NULL) {
                // delete last;
            }
        }
    }

    void output(string prefix)
    {
        cout << prefix << ':';
        CacheItem* c = this->head;
        
        while(c != NULL) {
            cout << c->data << ":";
            c = c->next;
        }
        cout << endl;
    }
};


int main() {
    LRUCache* cache = new LRUCache( 3/* capacity */ );

    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);
    cache->put(4, 4);
    cout << endl << cache->get(4);
    cout << endl << cache->get(3);
    cout << endl << cache->get(2);
    cout << endl << cache->get(1);
    cache->put(5, 5);
    cout << endl << cache->get(1);
    cout << endl << cache->get(2);
    cout << endl << cache->get(3);
    cout << endl << cache->get(4);
    cout << endl << cache->get(5);
    
    return 0;
}