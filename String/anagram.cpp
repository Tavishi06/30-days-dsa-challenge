#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> mp;

        // Count characters in s
        for (char c : s)
        {
            mp[c]++;
        }

        // Remove characters using t
        for (char c : t)
        {
            mp[c]--;
        }

        // Check if all frequencies are zero
        for (auto x : mp)
        {
            if (x.second != 0)
            {
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