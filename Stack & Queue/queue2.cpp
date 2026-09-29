#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        s1.push(x);

    }
    
    int pop() {
        
        if(s2.empty()){
            
            while(!s1.empty()){
                
                int value = s1.top();
                s1.pop();
                s2.push(value);
           }
        }
        int value = s2.top();
        s2.pop();
        return value; 
    }
    
    int peek() {
        
        if(s2.empty()){
            
            while(!s1.empty()){
                
                int value = s1.top();
                s1.pop();
                s2.push(value);
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    
    MyQueue queue;
    
    int n;

    cout << " No. of elements u want to push: " << endl;
    cin >> n;

    cout << " Enter the elements: " << endl;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        queue.push(x);
    }

    cout << " Queue peek: " << queue.peek() << endl; // Output: 1
    cout << " Queue pop: " << queue.pop() << endl;  // Output: 1
    cout << " Queue empty: " << queue.empty() << endl; // Output: 0 (false)
    return 0;

}