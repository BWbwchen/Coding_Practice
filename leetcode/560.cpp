class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1;
        for (auto n : nums) {
            sum += n;
            ans += mp[sum-k];
            if (mp.count(sum)) {
                mp[sum] ++;
            } else {
                mp[sum] = 1;
            }
        }
        
        
        return ans;
    }
};
