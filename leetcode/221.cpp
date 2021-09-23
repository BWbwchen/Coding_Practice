class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        // dp[i][j] = the length of square that include point(i,j)
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        
        int ans = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (matrix[i-1][j-1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};
