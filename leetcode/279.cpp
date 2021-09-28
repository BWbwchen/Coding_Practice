class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        dp.push_back(0);
        
        while(dp.size() <= n) {
            int temp = 1000000;
            for (int i = 1; i*i <= dp.size(); ++i) {
                temp = min(temp, dp[dp.size()-i*i] + 1); 
            }
            dp.push_back(temp);
        }
        return dp[n];
    }
};
