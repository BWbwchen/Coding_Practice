#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4)
      return {};

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        int part_remain = target - nums[i] - nums[j];
        int left = j + 1;
        int right = nums.size() - 1;

        while (left < right) {
          int temp = nums[left] + nums[right];
          if (part_remain > temp) {
            left++;
          } else if (part_remain < temp) {
            right--;
          } else {
            ans.push_back({nums[i], nums[j], nums[left], nums[right]});

            // skip duplicate element
            int origin_left = nums[left];
            int origin_right = nums[right];
            while (left < right && origin_left == nums[left])
              left++;
            while (left < right && origin_right == nums[right])
              right--;
          }
        }

        // skip duplicate element
        while (j + 1 < nums.size() && nums[j + 1] == nums[j])
          j++;
      }
      // skip duplicate element
      while (i + 1 < nums.size() && nums[i + 1] == nums[i])
        i++;
    }
    return ans;
  }
};
