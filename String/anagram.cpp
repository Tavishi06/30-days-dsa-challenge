#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> mp;

        // Count characters in s
        for (char c : s) {
            mp[c]++;
        }

        // Subtract characters using t
        for (char c : t) {
            mp[c]--;
        }

        // Every character count should be 0
        for (auto x : mp) {
            if (x.second != 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    if (obj.isAnagram(s, t))
    {
        cout << "They are anagrams" << endl;
    }
    else
    {
        cout << "They are not anagrams" << endl;
    }

    return 0;
}