#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        long long sum = 0;
        
        for(int i=0; i<nums.size(); i++){

            int mini = INT_MAX;
            int maxi = INT_MIN;

            for(int j=i; j<nums.size(); j++){
                
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                
                sum += maxi - mini;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    long long result = solution.subArrayRanges(nums);
    cout << "Sum of subarray ranges: " << result << endl;
    cout << "Expected output: 4" << endl; // Expected output for the input {1, 2, 3}
    return 0;
}