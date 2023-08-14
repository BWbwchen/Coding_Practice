class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.length() == 0) return 0;
        
        vector<int> ans;
        int target = s[0]-'0';
        int count = 1;
        
        for(int i = 1; i < s.length(); ++i) {
            int num = s[i]-'0';
            if (num != target) {
                ans.push_back(count);
                target = num;
                count = 1;
            } else {
                count ++;
            }
        }
        ans.push_back(count);
        
        
        int ret = 0;
        for (int i = 0; i < ans.size() - 1; ++i) {
            ret += min(ans[i], ans[i+1]); 
        }
        return ret;
    }
};
