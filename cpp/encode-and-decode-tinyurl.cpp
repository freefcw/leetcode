#include <iostream>
#include <string>
#include <map>

using namespace std;

unsigned int BKDRHash(string s)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    int i = 0;
    while (i < s.size())
    {
        hash = hash * seed + s[i];
        i++;
    }

    return (hash & 0x7FFFFFFF);
}

string i2newChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


string int2str(unsigned int i) {
    string s;
    while(i > 61) {
        unsigned t = i % 62;
        s += i2newChar[t];
        i = i / 62;
    }
    return s;
}

class Solution {
private:
    map<string, string> urlDB;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = int2str(BKDRHash(longUrl));
        auto search = this->urlDB.find(key);
        if (search == this->urlDB.end()) {
            this->urlDB.insert(make_pair(key, longUrl));
        }
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto search = this->urlDB.find(shortUrl);
        if (search != this->urlDB.end()) {
            return search->second;
        }

        return "";
    }
};

int main(){
    char url[] = "https://leetcode.com/problems/next-permutation/";

    Solution solution;

    cout << solution.decode(solution.encode(url)) << endl;
}