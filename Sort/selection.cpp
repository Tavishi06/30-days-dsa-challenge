#include <iostream>
#include <vector>
using namespace std;

int main() {

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    vector<int> a(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Selection Sort
    for(int i = 0; i < n - 1; i++) {

        int min_index = i;

        for(int j = i + 1; j < n; j++) {

            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }

        if(min_index != i) {
            swap(a[i], a[min_index]);
        }
    }

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}