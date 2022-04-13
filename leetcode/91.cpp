class Solution {
public:
  int numDecodings(string s) {
    if (s.length() == 0) {
      return 1;
    }

    vector<int> dp(s.length() + 1, 0);

    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : 1;

    for (int i = 2; i <= s.length(); ++i) {
      // dp[i] = dp[i-1] + dp[i-2]
      if (s[i - 1] != '0') {
        dp[i] += dp[i - 1];
      }

      int probe = stoi(s.substr(i - 2, 2));
      if (9 < probe && probe < 27) {
        dp[i] += dp[i - 2];
      }
    }

    return dp[s.length()];
  }
};
