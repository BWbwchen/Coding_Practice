class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp_max = nums[0];
        int dp_min = nums[0];
        int ans = dp_max;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            int pre_dp_max = dp_max;
            dp_max = max(max(num, num*dp_max), num*dp_min); 
            dp_min = min(min(num, num*pre_dp_max), num*dp_min); 
            ans = max(ans, dp_max);
        }
        return ans;
    }
};
