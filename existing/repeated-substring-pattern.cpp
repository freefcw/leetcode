#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> divisors = this->getDivisors(s.size());
        for(int i = 0; i < divisors.size(); i++) {
            if (this->isRepeat(s, divisors[i])) {
                return true;
            }
        }
        return false;
    }

    vector<int> getDivisors(int size) {
        int last = size;
        vector<int> numbers;
        numbers.push_back(1);
        for(int i = 2; i < last; i++)  {
            if (size % i == 0) {
                last = size / i;
                numbers.push_back(last);
                if (i == last) {
                    break;
                }
                numbers.push_back(i);
            }
        }
        sort(numbers.begin(), numbers.end(), greater<int>());
        return numbers;
    }

    bool isRepeat(string s, int b) {
        int repeat_count = s.size() / b;
        if (repeat_count < 2) {
            return false;
        }
        for(int i = 0; i < b; i++) {
            for(int k = 1; k < repeat_count; k++) {
                if (s[i] != s[k * b + i]) {
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
    cout << s.repeatedSubstringPattern("ababab") << endl;
    cout << s.repeatedSubstringPattern("abcabc") << endl;
    cout << s.repeatedSubstringPattern("") << endl;

    // vector<int> res = s.getDivisors(100);
    // for(int i = 0; i < res.size(); i++) {
    //     cout << res[i] << endl;
    // }
    // for(int i = 1; i < 16; i++) {
    //     cout << i << "=>" << s.isRepeat("aaaaaaaaaaaa", i) << endl;
    // }



    return 0;
}