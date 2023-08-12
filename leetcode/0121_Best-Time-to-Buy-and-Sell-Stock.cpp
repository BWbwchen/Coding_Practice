// Simple DP:
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // dp[i] ->  maximum value in range [i, end]
        // formulation:
        vector<int> dp(prices.size(), 0);
        dp[prices.size() - 1] = prices.back();
        for (int i = prices.size() - 2; i >= 0; --i) {
            dp[i] = max(dp[i + 1], prices[i]);
        }

        int ret = 0;
        for (int i = 0; i < prices.size(); ++i) {
            // if we buy today, the possible maximum value is dp[i]
            ret = max(ret, dp[i] - prices[i]);
        }

        return ret;
    }
};
// Old DP:
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        vector<int> delta(prices.size() - 1, 0);
        for (int i = 0; i < prices.size() - 1; ++i) {
            delta[i] = prices[i + 1] - prices[i];
        }
        vector<int> dp(delta.size(), 0);
        dp[0] = delta[0];
        int answer = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 1], 0) + delta[i];
            answer = max(answer, dp[i]);
        }
        if (answer < 0)
            return 0;
        else
            return answer;
    }
};
