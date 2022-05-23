#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int t = -1;
    // find the first element with value val.
    for (int i = 0; t == -1 && i < nums.size(); ++i) {
      if (nums[i] == val)
        t = i;
    }

    if (t == -1)
      return nums.size();

    for (int i = t + 1; i < nums.size(); ++i) {
      if (nums[i] != val)
        swap(nums[i], nums[t++]);
    }
    return t;
  }
};
