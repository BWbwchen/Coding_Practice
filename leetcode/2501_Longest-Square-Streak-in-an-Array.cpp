class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<unsigned long long int> us;
        for (auto &n : nums)
            us.emplace(n);
        
        int ans = -1;
        
        for (auto &n : nums) {
            unsigned long long int find = n;
            int len = 1;
            while(true) {
                find = find * find;
                if (us.count(find) <= 0)
                    break;
                len++;
            }
            if (len > 1)
                ans = max(ans, len);
        }
        return ans;
    }
};
