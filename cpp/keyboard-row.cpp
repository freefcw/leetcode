#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
private:
    int keyMap[26];
public:
    Solution() {
        int keys[] = {
            2, 3, 3, 2, 1, 2, 2,
            2, 1, 2, 2, 2, 3, 3,
            1, 1, 1, 1, 2, 1,
            1, 3, 1, 3, 1, 3
        };
        for(int i = 0; i < 26; i++) {
            this->keyMap[i] = keys[i];
        }
        
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> results;
        for(int i = 0; i < words.size(); i++) {
            if (this->match(words[i])) {
                results.push_back(words[i]);
            }
        }
        return results;
    }

    bool match(string word) {
        int row = this->getRow(word[0]);
        for(int i = 1; i < word.size(); i++) {
            if (row != this->getRow(word[i])) {
                return false;
            }
        }
        return true;
    }

    int getRow(char ch) {
        ch = tolower(ch);
        return this->keyMap[ch - 'a'];
    }
};

int main()
{
    Solution s;
    vector<string> words;
    words.push_back("Hello");
    words.push_back("Alaska");
    words.push_back("Dad");
    words.push_back("Peace");
    vector<string> result = s.findWords(words);
    for(int i = 0; i < result.size();i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}