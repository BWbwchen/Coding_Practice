class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // shifted ans
        vector<int> ans(nums.size());
        
        // left part
        ans[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
