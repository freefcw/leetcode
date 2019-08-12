#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int from, int to) {
        while(true) {
            if (from >= to) {
                break;
            }
            if (s[from] != s[to]) {
                return false;
            }
            from++;
            to--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if (s.size() < 2) {
            return true;
        }
        int head = 0;
        int tail = s.size() - 1;
        while(true) {
            if (head >= tail) {
                return true;
            }
            if (s[head] != s[tail]) {
                return this->isPalindrome(s, head+1, tail)
                 || this->isPalindrome(s, head, tail -1);
            }
            head++;
            tail--;
        }
    }
};
// https://leetcode.com/problems/valid-palindrome-ii/
class Solution2 {
public:
    bool validPalindrome(string s) {
        if (s.size() < 2) {
            return true;
        }
        int i = 0;
        int tail = s.size() - 1;
        bool isDeleted = false;
        bool isOk = true;
        while(isOk) {
            if (i >= tail) {
                break;
            }
            if (s[i] != s[tail]) {
                if (isDeleted) {
                    isOk = false;
                    break;
                }
                if (i + 1 == tail) {
                    return true;
                }
                if (s[i + 1] == s[tail]) {
                    i++;
                    isDeleted = true;
                }
                if (!isDeleted) {
                    isOk = false;
                }
            }
            i++;
            tail--;
        }
        if (isOk) {
            return true;
        }
        i = 0;
        tail = s.size() - 1;
        isDeleted = false;
        while(true) {
            if (i >= tail) {
                break;
            }
            if (s[i] != s[tail]) {
                if (isDeleted) {
                    return false;
                }
                if (i + 1 == tail) {
                    return true;
                }
                if (s[i] == s[tail - 1]) {
                    tail--;
                    isDeleted = true;
                }
                if (!isDeleted) {
                    return false;
                }
            }
            i++;
            tail--;
        }

        return true;
    }
};

int main()
{
    Solution s;


    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("aaba") << endl;
    cout << s.validPalindrome("aabca") << endl;
    cout << s.validPalindrome("abca") << endl;
    cout << s.validPalindrome("abcdea") << endl;
    cout << s.validPalindrome("deeee") << endl;
    cout << s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << endl;



    return 0;
}