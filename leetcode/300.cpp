// dp version, O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        int ans = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) dp[i] = max(dp[i], dp[j]+1);   
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > v.back()) {
                v.push_back(nums[i]);
            } else {
                int pos = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[pos] = nums[i];
            }
        }
        
        return v.size();
    }
};
