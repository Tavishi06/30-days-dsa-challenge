#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    string sentence;
    cout << "Write a sentence : ";
    getline(cin, sentence);

    cout << "Reversed Sentence - ";

    stringstream ss(sentence);
    string word;

    vector<string> words;

    // Store each word
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the words
    reverse(words.begin(), words.end());

    // Print the reversed sentence
    for (string word : words) {
        cout << word << " ";
    }

    return 0;
}