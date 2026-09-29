#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        if(q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if (!q1.empty()) {
            int value = q1.front();
            q1.pop();
            return value;
        }
        else{
            int value = q2.front();
            q2.pop();
            return value;
        }
    }
    
    int top() {
        if(!q1.empty()){
            return q1.front();
        }
        else{
            return q2.front();
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << "stack.top() = " << stack.top() << endl; // Output: 2
    cout << "stack.pop() = " << stack.pop() << endl; // Output: 2
    cout << "stack.empty() = " << stack.empty() << endl; // Output: 0 (false)
    return 0;
}