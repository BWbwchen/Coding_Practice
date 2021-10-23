class Solution {
public:
    int countSubstrings(string s) {
        // dp
        // dp[i][j], s[i ~ j] is palindrone or not
        // dp[i][j] = (s[i] == s[j]) && dp[i-1][j-1]
        vector<vector<bool>> dp(s.size()+1, vector<bool>(s.size()+1, false));
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][i] = true;
        }
        for (int i = 1; i < s.size(); ++i) {
            dp[i][i+1] = (s[i-1] == s[i]);
        }
        
        for (int j = 3; j <= s.size(); ++j) {
            for (int i = 1; i <= j-2; ++i) {
                dp[i][j] = (s[i-1] == s[j-1]) && dp[i+1][j-1];
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i; j <= s.size(); ++j) {
                if (dp[i][j]) ans++;
            }
        }
        return ans;
    }
};
