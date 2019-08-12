#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() < 2) {
            return true;
        }
        bool isUpperStart = isupper(word[0]);
        bool allLower = islower(word[0]) || (isUpperStart && islower(word[1]));
        bool allUpper = isUpperStart && isupper(word[1]);
        for (int i = 1; i < word.size(); i++)
        {
            if (islower(word[i]) && allUpper) {
                return false;
            }
            if (isupper(word[i]) && allLower) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.detectCapitalUse("USA") << endl;
    cout << s.detectCapitalUse("Flowerc") << endl;
    cout << s.detectCapitalUse("UssssA") << endl;
    cout << s.detectCapitalUse("UsSssA") << endl;
    cout << s.detectCapitalUse("g") << endl;
    cout << s.detectCapitalUse("leatcode") << endl;
    cout << s.detectCapitalUse("FFFFFFf") << endl;

    return 0;
}