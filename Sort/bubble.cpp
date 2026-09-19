#include<iostream>
#include<vector>

using namespace std;

class BubbleSort {
    public:
        void sort(vector<int>& arr){

            int n = arr.size();
            
            for(int i = 0; i < n-1; i++){
                for(int j = 0; j < n-i-1; j++){
                    if(arr[j] > arr[j+1]){
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
        }
};

int main(){

    vector<int> arr = {64, 34, 37, 98, 10, 90, 299, 3};

    BubbleSort bs;
    bs.sort(arr);

    cout << "Sorted array - ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}