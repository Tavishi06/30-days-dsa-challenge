#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> getConcatenation(vector<int> &nums)
  {

    int x = nums.size();
    nums.resize(2 * x);

    for (int i = 0; i < x; i++)
    {
      nums[x + i] = nums[i];
    }
    return nums;
  }
};

int main()
{
  Solution obj;

  vector<int> nums = {1, 2, 3};

  vector<int> ans = obj.getConcatenation(nums);

  for (int x : ans)
  {
    cout << x << " ";
  }

  return 0;
}