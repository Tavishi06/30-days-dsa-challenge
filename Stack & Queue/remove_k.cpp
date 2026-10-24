#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string st = "";

        for(int i=0; i<num.size(); i++){
            char digit = num[i];

            while(!st.empty() && k>0 && st.back() > digit){
                st.pop_back();
                k--;
            } 

            st.push_back(digit);
        }

        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }

        int pos = st.find_first_not_of('0');

        if (pos == string::npos) {
            return "0";
        }

        return st.substr(pos);;
    }
};

int main() {
    Solution solution;
    string num = "1432219";
    int k = 3;
    string result = solution.removeKdigits(num, k);
    cout << "Result: " << result << endl; // Output: "1219"
    return 0;
}