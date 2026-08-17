#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class solution
{
  public:
  int secondLargestElement(vector<int> &A)
  {
    int n = A.size();
    
    int secondLargest = -1;

    if(n < 2)
    return -1;

    sort(A.begin(),A.end());

    int Largest = A[0];

    for (int i = 1; i < n; i++)
    {
      if (A[i] > Largest)
      {
        secondLargest = Largest;
        Largest = A[i];
      }
      else if (A[i] > secondLargest && A[i] != Largest)
      {
        secondLargest = A[i];
      }
    }
    return secondLargest;
  }
};

int main()
{
  vector<int> A = {1, 7, 2, 3, 0, 2, 4,10, 8};

  solution obj;
  int ans = obj.secondLargestElement(A);

  cout << "Second Largest Element: " << ans << endl;

  return 0;
}