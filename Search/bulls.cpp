#include <string>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        int countSecret[10] = {};
        int countGuess[10] = {};

        // Step 1: Find bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                countSecret[secret[i] - '0']++;
                countGuess[guess[i] - '0']++;
            }
        }

        // Step 2: Find cows
        for (int i = 0; i < 10; i++) {
            cows += min(countSecret[i], countGuess[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    Solution solution;
    string secret = "1807";
    string guess = "7810";
    cout << solution.getHint(secret, guess) << endl;
    return 0;
}