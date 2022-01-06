// O(n^2)
class Solution {
public:
  long long subArrayRanges(vector<int> &nums) {
    long long ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      long long Max = nums[i];
      long long Min = nums[i];
      for (int j = 1; i + j < nums.size(); ++j) {
        Max = max(Max, (long long)nums[i + j]);
        Min = min(Min, (long long)nums[i + j]);
        ans += Max - Min;
      }
    }
    return ans;
  }
};

// O(n)
