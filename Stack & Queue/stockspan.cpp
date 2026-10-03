#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    for (int price : prices) {
        int span = obj->next(price);
        cout << "Price: " << price << ", Span: " << span << endl;
    }

    delete obj;
    return 0;
}   

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */