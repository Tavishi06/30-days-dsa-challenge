#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int j = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        nums[j] = nums[i];
        j++;
      }
    }

    // Fill remaining positions with zero
    while (j < nums.size())
    {
      nums[j] = 0;
      j++;
    }
  }
};

int main()
{
  Solution obj;
  vector<int> nums = {0, 1, 0, 3, 12};

  obj.moveZeroes(nums);

  cout << "Array after moving zeroes: ";
  for (int x : nums)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
