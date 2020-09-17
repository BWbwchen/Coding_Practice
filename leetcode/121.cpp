class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int > delta(prices.size()-1, 0);
        for (int i = 0; i < prices.size()-1; ++i) {
            delta[i] = prices[i+1] - prices[i];
        }
        vector<int > dp(delta.size(), 0);
        dp[0] = delta[0];
        int answer = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(dp[i-1], 0) + delta[i];
            answer = max(answer, dp[i]);
        }
        if (answer < 0) return 0;
        else return answer;
    }
};
