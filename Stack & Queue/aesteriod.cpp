#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;

        for (int i = 0; i < a.size(); i++) {
            bool alive = true;

            while (!st.empty() && st.top() > 0 && a[i] < 0) {

                if (st.top() < abs(a[i])) {
                    st.pop();
                }
                else if (st.top() == abs(a[i])) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(a[i]);
            }
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = solution.asteroidCollision(asteroids);
cout << "Program is running!" << endl;
    cout << "Result: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl; // Output: "5 10"

    return 0;
}