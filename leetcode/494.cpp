// brute force with memorization
class Solution {
public:
    // length, target
    unordered_map<string, int> mp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return re(nums.size()-1, nums, target); 
    }
    
    int re(int len, vector<int> nums, int target) {
        auto pp = make_pair(len, target);
        string ps = to_string(pp.first) + "_" + to_string(pp.second);
        if (mp.count(ps) > 0) {
            return mp[ps];
        }
        if (len == -1) {
            if (target == 0) return 1;
            else return 0;
        }
        auto last = nums[len];
        
        int original_len = nums.size();
        int left = re(len-1, nums, target+last);
        int right = re(len-1, nums, target-last);
        mp[ps] = left + right;
        
        return left + right;
    }
};

// dp version
class Solution {
public:
    // This problem can be written as :
    //      sum(p) - sum(n) = target
    // =>   sum(p) - sum(n) + sum(p) + sum(n) = target + sum(p) + sum(n)
    // =>   2 * sum(p) = target + sum(all)
    // =>   sum(p) = (target + sum(all))/2
    // what is p?
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0; 
        for (auto i : nums) total_sum += i;
        if (target < -total_sum || total_sum < target || (total_sum + target) & 1) return 0;
        return subsum(nums, (total_sum + target) >> 1);
    }
    
    int subsum(vector<int> nums, int sum) {
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = sum; i >= n; --i)
                dp[i] = dp[i] + dp[i-n];
        }
        return dp[sum];
    }
};
