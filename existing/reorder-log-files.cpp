#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digit_logs;
        vector<string> letters;
        for (int i = 0; i < logs.size(); i++)
        {
            string key = this->parseKey(logs[i]);
            if (isdigit(key[0])) {
                digit_logs.push_back(logs[i]);
            } else {
                letters.push_back(key);
            }
        }
        sort(letters.begin(), letters.end());
        vector<string> result;
        for(int i = 0; i < letters.size();i++) {
            result.push_back(this->recover(letters[i]));
        }
        for(int i = 0; i < digit_logs.size();i++) {
            result.push_back(digit_logs[i]);
        }
        
        return result;
    }

    string recover(string s) {
        int pos = s.find('#');
        
        string value = s.substr(pos + 1) + " " + s.substr(0, pos);

        return value;
    }

    string parseKey(string s) {
        int pos = s.find(' ');

        string value = s.substr(pos + 1) + "#" + s.substr(0, pos);

        return value;
    }
};

int main()
{
    Solution s;
    vector<string> incomes;
    incomes.push_back("a1 9 2 3 1");
    incomes.push_back("g1 act car");
    incomes.push_back("a1 act car");
    incomes.push_back("zo4 4 7");
    incomes.push_back("ab1 off key dog");
    incomes.push_back("a8 act zoo");

    vector<string> result = s.reorderLogFiles(incomes);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    

    return 0;
}