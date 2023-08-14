class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        // sum of subarray -> think about prefix sum
        // If we havee prefix sum, what can we do?

        int prefix = 0;
        int answer = 0;
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (auto &n : nums) {
            prefix += n;
            answer += dp[prefix - k];
            dp[prefix]++;
        }
        return answer;
    }
};
