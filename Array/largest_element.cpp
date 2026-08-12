#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
  int largestElement(vector<int> &A)
  {
    int n = A.size();

    int count = 0;
    
    if(n == 0)
    return -1;

    while(n > 0)
    {
      count = max(count, A[n-1]);
      n--;
    }

    return count;
  }
};

int main()
{
  vector<int> A = {1, 1, 2, 3, 3, 4, 4, 8, 8};

  Solution obj;
  int ans = obj.largestElement(A);

  cout << "Largest Element: " << ans << endl;

  return 0;
}