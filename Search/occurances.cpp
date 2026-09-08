#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    
            vector<int> positions;
            vector<int> answer;
    
            // Store indexes where x occurs
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == x) {
                    positions.push_back(i);
                }
            }
    
            // Answer each query
            for (int q : queries) {
    
                if (q <= positions.size()) {
                    answer.push_back(positions[q - 1]);
                }
                else {
                    answer.push_back(-1);
                }
            }
    
            return answer;
        }
    };

    int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> queries = {1, 3, 5};
    int x = 3;
    vector<int> answer = sol.occurrencesOfElement(nums, queries, x);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    return 0;
}