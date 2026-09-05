#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
            unordered_map<string, vector<string>> mp;
    
            for (string s : strs) {
    
                string key = s;
    
                sort(key.begin(), key.end());
    
                mp[key].push_back(s);
            }
    
            vector<vector<string>> ans;
    
            for (auto x : mp) {
                ans.push_back(x.second);
            }
    
            return ans;
        }
    };

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}