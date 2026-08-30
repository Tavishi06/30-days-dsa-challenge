#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {

    for (int i = num.size() - 1; i >= 0; i--) {

        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }

    return "";
}

int main() {

    string num;

    cout << "Enter number: ";
    cin >> num;

    string result = largestOddNumber(num);

    cout << "Largest odd number: " << result << endl;

    return 0;
}