#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1000000007;

        vector<int> left(n), right(n);
        stack<int> st;

        // 1. Find left distances
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }

            st.push(i);
        }

        // 2. Clear the stack
        while (!st.empty()) {
            st.pop();
        }

        // 3. Find right distances
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }

            st.push(i);
        }

        // 4. Add each element's contribution
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long contribution =
                (1LL * arr[i] * left[i] % MOD) * right[i] % MOD;

            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};
int main() {
    Solution solution;
    vector<int> arr = {3, 1, 2, 4};
    int result = solution.sumSubarrayMins(arr);
    cout << "Program is running!" << endl;
    cout << "Result: " << result << endl; // Output: 17

    return 0;
}