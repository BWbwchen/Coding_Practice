class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001] = {0};
        // dp[i][j] = the lps of s[i..j]
        
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][i] = 1;
        }
        
        for (int j = 2; j <= s.size(); ++j) {
            for (int i = j-1; i > 0; --i) {
                if (s[i-1] == s[j-1]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[1][s.size()];
    }
};
