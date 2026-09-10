#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int beg = 0;
            int end = nums.size() - 1;
    
            while (beg <= end) {
    
                int mid = beg + (end - beg) / 2;
    
                if (nums[mid] < target) {
                    beg = mid + 1;
                }
                else if (nums[mid] > target) {
                    end = mid - 1;
                }
                else {
                    return mid;
                }
            }
            return beg;            
        }
    };

    int main() {
        Solution solution;
        vector<int> nums = {1, 3, 5, 6};
        int target = 5;
        int result = solution.searchInsert(nums, target);
        cout << result << endl;
        return 0;
    }