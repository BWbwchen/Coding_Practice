class Solution {
public:
  int minCost(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 0x3f3f3f3f);
    dp[0] = k;
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int> freq;
      int sum = 0;
      for (int j = i; j >= 0; --j) {
        freq[nums[j]]++;
        if (freq[nums[j]] == 2)
          sum += 2;
        else if (freq[nums[j]] > 2)
          sum++;

        if (j == 0)
          dp[i] = min(dp[i], k + sum);
        else
          dp[i] = min(dp[i], k + dp[j - 1] + sum);
      }
    }
    return dp[n - 1];
  }
};
