class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] = the lcs of nums1[0..i] and nums2[0..j]
        // dp[i][j] = 0 if nums[i] != nums[j]
        // dp[i][j] = dp[i-1][j-1]+1 if nums[i] == nums[j]
        
        int dp[1001][1001] = {0};
        int ans = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }  
            }
        }
        
        return ans;
    }
};
