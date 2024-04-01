#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target)
  {
    if (nums.empty()) {
      return {-1, -1};
    }

    int lower = 0, upper = nums.size() - 1;
    while (lower < upper) {
      int index = lower + (upper - lower) / 2;
      if (nums[index] >= target) {
        upper = index;
      } else {
        lower = index + 1;
      }
    }

    if (nums[lower] != target) {
      return  {-1,-1};
    }

    int L = lower;
    upper = nums.size() - 1;
    while (lower < upper) {
      int index = lower + (upper - lower + 1) / 2;
      if (nums[index] <= target) {
        lower = index;
      } else {
        upper = index - 1;
      }
    }

    return {L, lower};
  }
};

int main()
{
  Solution sol;
  vector<int> nums{5, 7, 7, 8, 8, 10};
  for (auto i : sol.searchRange(nums, 8)) cout << i << " ";
  for (auto i : sol.searchRange(nums, 6)) cout << i << " ";
  nums = {};
  for (auto i : sol.searchRange(nums, 0)) cout << i << " ";
  nums = {1};
  for (auto i : sol.searchRange(nums, 1)) cout << i << " ";
  nums = {2, 2};
  for (auto i : sol.searchRange(nums, 3)) cout << i << " ";

  return 0;
}
