#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
    
            vector<int> ans(nums.size());
    
            int posint = 0;
            int negint = 1;
    
            for(int x : nums) {
    
                if(x > 0) {
                    ans[posint] = x;
                    posint += 2;
                }
                else {
                    ans[negint] = x;
                    negint += 2;
                }
            }
    
            return ans;
        }
    };


    int main() {

        Solution obj;
    
        vector<int> nums = {3, 1, -2, -5, 2, -4};
    
        vector<int> ans = obj.rearrangeArray(nums);
    
        cout << "Rearranged array: ";
    
        for (int x : ans) {
            cout << x << " ";
        }
    
        cout << endl;
    
        return 0;
    }
