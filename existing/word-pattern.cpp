
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> mapping(27);

        vector<string> segments;
        int start = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ') {
                segments.push_back(str.substr(start, i - start));
                start = i + 1;
            }
        }
        segments.push_back(str.substr(start, str.size() - start));
        if (pattern.size() != segments.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i)
        {
            int index = pattern[i] - 'a';
            if (mapping[index].size() == 0) {
                mapping[index] = segments[i];
            } else {
                if (segments[i] != mapping[index]) {
                    // cout << i << ':' << segments[i]  << '|' << mapping[pattern[i]] << endl;
                    return false;
                }
            }
        }

        for (int i = 0; i < mapping.size(); ++i)
        {
            // cout << mapping[i] << "|" << endl;
            if (mapping[i].size() == 0) {
                break;
            }
            for (int k = i + 1; k < mapping.size(); ++k)
            {
                // cout << mapping[i] << "|" << mapping[k] << endl;
                if (mapping[k].size() == 0) {
                    break;
                }
                if (mapping[i] == mapping[k]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << s.wordPattern("aaaa", "dog dog dog dog") << endl;
    cout << s.wordPattern("jquery", "jquery") << endl;

    return 0;
}