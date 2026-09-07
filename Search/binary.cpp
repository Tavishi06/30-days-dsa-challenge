#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
    
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
    
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int result = sol.search(nums, target);
    cout << "Result: " << result << endl;
    return 0;
}