class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        string ret(1000, 'x');
        for (int i = 0; i < strs.size() - 1; ++i) {
            string temp_ans = "";
            int min_length = min(strs[i].size(), strs[i+1].size());
            for (int j = 0; j < min_length; ++j) {
                if (strs[i][j] != strs[i+1][j]) {
                    break; 
                }
                temp_ans += strs[i][j];
            }
            
            if (temp_ans.size() < ret.size()) ret = temp_ans;
        }
        return ret;
    }
};
