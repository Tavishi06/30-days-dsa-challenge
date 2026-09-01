#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string longest_prefix(vector<string>& strs) {
    
            string prefix = strs[0];
    
            for (int i = 1; i < strs.size(); i++) {
    
                int j = 0;
    
                while (j < prefix.size() &&
                       j < strs[i].size() &&
                       prefix[j] == strs[i][j]) {
                    j++;
                }
    
                prefix = prefix.substr(0, j);
    
                if (prefix == "") {
                    return "";
                }
            }
    
            return prefix;
        }
    };


int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << solution.longest_prefix(strs) << endl;
    return 0;
}