// DP version
class Solution {
public:
    int jump(vector<int>& nums) {
        int MAXN = 20000000;
        vector<int> dp(nums.size(), MAXN);
        dp[nums.size()-1] = 0;
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = 1; j <= nums[i] && j+i < nums.size(); ++j) {
                dp[i] = min(dp[i], 1 + dp[i+j]);
            }     
        }
        return dp[0];
    }
};
