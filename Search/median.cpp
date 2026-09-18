#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr;

        int i = 0;
        int j = 0;

        // Merge both sorted arrays
        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] <= nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        // Remaining elements of nums1
        while (i < nums1.size()) {
            arr.push_back(nums1[i]);
            i++;
        }

        // Remaining elements of nums2
        while (j < nums2.size()) {
            arr.push_back(nums2[j]);
            j++;
        }

        // Find median
        int n = arr.size();

        if (n % 2 == 1) {
            return arr[n / 2];
        }
        else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.5

    return 0;
}