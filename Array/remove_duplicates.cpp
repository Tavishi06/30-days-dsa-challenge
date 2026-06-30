#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int count = 0;
    int x = nums.size();
    for (int i = 1; i < x; i++)
    {
      if (nums[i] == nums[i - 1])
      {
        count++;
      }
      else
      {
        nums[i - count] = nums[i];
      }
    }
    return nums.size() - count;
  }
};

int main()
{
  Solution obj;

  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  int k = obj.removeDuplicates(nums);

  cout << "Number of unique elements: " << k << endl;

  cout << "Array after removing duplicates: ";

  for (int i = 0; i < k; i++)
  {
    cout << nums[i] << " ";
  }

  return 0;
}