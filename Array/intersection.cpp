#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &a, vector<int> &b)
  {
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
      for (int j = 0; j < b.size(); j++)
      {
        if (a[i] == b[j])
        {
          if (find(ans.begin(), ans.end(), a[i]) == ans.end())
          {
            ans.push_back(a[i]);
          }
        }
      }
    }
    return ans;
  }
};

int main()
{
  vector<int> a = {1, 2, 2, 1};
  vector<int> b = {2, 2};

  Solution obj;
  vector<int> result = obj.intersection(a, b);

  cout << "Intersection: ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}