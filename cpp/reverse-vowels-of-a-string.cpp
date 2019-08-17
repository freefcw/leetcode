#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<char> vowels;
        for (int i = 0; i < s.size(); i++)
        {
            if (this->isVowel(s[i]))
            {
                vowels.push_back(s[i]);
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (this->isVowel(s[i]))
            {
                s[i] = vowels.back();
                vowels.pop_back();
            }
        }
        return s;
    }

    bool isVowel(char ch)
    {
        char v = tolower(ch);
        if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;

    cout << s.reverseVowels("bcd") << endl;

    return 0;
}