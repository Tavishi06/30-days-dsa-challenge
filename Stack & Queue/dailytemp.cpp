#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answer(temperatures.size(), 0);
        
        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prev = st.top();
                st.pop();
                answer[prev] = i - prev;
            }   
            st.push(i);
        }
        return answer;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution obj;
    
    vector<int> ans = obj.dailyTemperatures(temperatures);
    cout << "Answer: ";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}