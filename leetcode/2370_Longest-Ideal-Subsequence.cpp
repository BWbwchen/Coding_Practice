class Solution {
public:
    inline bool valid(char a, char b, int k) {
        return abs(a - b) <= k;
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26, 0); // a ~ z

        for (auto c : s) {
            int tmp = std::numeric_limits<int>::min();
            for (char j = 'a'; j <= 'z'; ++j) {
                // dp[c] = max_j(dp[j]) + 1, where valid(j, c, k) == true
                if (valid(j, c, k))
                    tmp = max(tmp, dp[j-'a']);
            }
            // Why use tmp? Because we can not update the dp[c-'a'] and compare it simultaneously.
            dp[c-'a'] = max(dp[c-'a'], tmp + 1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
