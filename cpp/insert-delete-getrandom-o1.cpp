#include <iostream>
#include <map>
#include <vector>
#include <random>

class RandomizedSet
{
private:
    std::vector<int> dataList;
    std::map<int, int> dataMap;
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        auto search = this->dataMap.find(val);
        if (search == this->dataMap.end()) {
            this->dataList.push_back(val);
            this->dataMap.insert(std::make_pair(val, this->dataList.size() - 1));
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        auto search = this->dataMap.find(val);
        if (search != this->dataMap.end()) {
            int tailIndex = this->dataList.size() - 1;
            if (search->second != tailIndex) {
                auto lastItem = this->dataList[tailIndex];
                // std::cout << "move " << *lastItem << "to " << search->second << std::endl;
                this->dataMap[lastItem] = search->second;
                this->dataList[search->second] = lastItem;
            }
            this->dataMap.erase(search);
            this->dataList.pop_back();

            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        if (this->dataList.size() == 0) {
            return -1;
        }
        // std::cout << "list: ";
        // for (int i = 0; i < this->dataList.size();i++) {
        //     std::cout << this->dataList[i] << " ";
        // }
        // std::cout << std::endl;
        int random_var = std::rand() % this->dataList.size();
        return this->dataList[random_var];
    }
};

void printBool(bool b) {
    if (b) {
        std::cout << "true" << std::endl;
    }
    std::cout << "false" << std::endl;
}

int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool param = obj->insert(3);
    printBool(param);
    param = obj->insert(3);
    printBool(param);
    int param_3 = obj->getRandom();
    std::cout << param_3 << std::endl;
    param = obj->remove(2);
    printBool(param);
    param = obj->insert(2);
    param = obj->insert(4);
    param = obj->insert(5);
    param_3 = obj->getRandom();
    std::cout << param_3 << std::endl;
    printBool(param);
    param = obj->remove(2);
    printBool(param);
    param_3 = obj->getRandom();
    std::cout << param_3 << std::endl;
    param_3 = obj->getRandom();
    std::cout << param_3 << std::endl;
    param = obj->remove(2);
    printBool(param);

    return 0;
}