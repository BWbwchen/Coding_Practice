// brute force
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);

        // [j, i)
        // i -> end index
        for (int i = 1; i <= s.size(); ++i) {
            // j -> start index 
            for (int j = 0; j < i; ++j) {
                string substring = s.substr(j, i-j);

                if (contain(wordDict, substring) && (j == 0 || dp[j-1])) {
                    dp[i-1] = true;
                }
            }
        }
        return dp[s.size()-1];
    }
    
    bool contain(vector<string>& wordDict, string substring) {
        for (int i = 0; i < wordDict.size(); ++i) {
            if (wordDict[i] == substring) {
                return true;
            }
        }
        return false;
    }
};
