class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        
        for (int i = 1; i <= n; ++i) {
            /*
            int log = (int)log2(i);
            dp[i] = dp[i - (1 << log)] + 1;
            */
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
