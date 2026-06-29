#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int count = 0, max = 0;
    int y = nums.size();
    for (int i = 0; i < y; i++)
    {
      if (nums[i] == 1)
      {
        count = count + 1;
        if (max < count)
        {
          max = count;
        }
      }
      else
      {
        count = 0;
      }
    }
    return max;
  }
};

int main()
{
  Solution obj;

  vector<int> nums = {1, 1, 0, 1, 1, 1};

  cout << "Maximum consecutive 1's = "
       << obj.findMaxConsecutiveOnes(nums) << endl;

  return 0;
}