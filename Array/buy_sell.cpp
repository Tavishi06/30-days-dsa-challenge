#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        int bestBuy = prices[0];

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }

            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};

int main() {

    Solution obj;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = obj.maxProfit(prices);

    cout << "Maximum Profit: " << ans << endl;

    return 0;
}