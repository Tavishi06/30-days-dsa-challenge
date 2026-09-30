#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        for(int i=0; i<nums1.size(); i++){
            
            for(int j=0; j<nums2.size(); j++){
                
                if(nums1[i] == nums2[j]){
                    
                    int greater = -1;
                    
                    for(int k=j+1; k<nums2.size(); k++){
                    
                        if(nums2[k] > nums2[j]){
                            greater = nums2[k];
                            break;
                        }
                    }
                    ans.push_back(greater);
                }
            }
        }
        return ans;
    }
};

int main() { 
    vector<int> nums1 = {4, 1, 2}; 
    vector<int> nums2 = {1, 3, 4, 2}; 
    
    Solution obj; 
    
    vector<int> ans = obj.nextGreaterElement(nums1, nums2); 
    
    cout << "Answer: "; 
    
    for(int x : ans) { 
        cout << x << " "; 
    } 
    
    cout << endl; 
    
    return 0;
}