// dp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        
        
        dp[0][0] = true;
        // initialize
        for (int i = 1; i <= p.size(); ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1];
            }
        }
        
        // calculate
        for (int j = 1; j <= p.size(); ++j) {
            for (int i = 1; i <= s.size(); ++i) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else if (p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    if (s[i-1] == p[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        return dp[s.size()][p.size()];
        
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, star = -1, ss = 0;
        
        while(si < s.size()) {
            if ((s[si] == p[pi]) || (p[pi] == '?') ) {
                si++;
                pi++;
            } else if (p[pi] == '*') {
                star = pi;
                pi++;
                ss = si;
            } else if (star >= 0) {
                pi = star + 1;
                ss++;
                si = ss;
            } else {
                return false;
            }
        }
        
        while(p[pi] == '*') pi++;
        
        
        return pi == p.size();
        
    }
};
