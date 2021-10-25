class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> dp(26, 0);
        vector<int> ret;
        for (int i = 0; i < s.size(); ++i) {
            dp[s[i] - 'a'] = i;
        }
        
        int temp_end = 0, anchor = 0;
        for (int i = 0; i < s.size(); ++i) {
            temp_end = max(temp_end, dp[s[i]-'a']); 
            if (temp_end == i) {
                ret.push_back(i-anchor+1); 
                anchor = i+1;
            }
        }
        return ret;
    }
};
