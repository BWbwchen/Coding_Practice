// DP method, dp[i] means end at ith non-continuous valid length
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        if (s.size() == 0) return 0;
        vector<int> dp(s.size(), 0); 
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if ( s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0)  + 2;
                } else if ((i - dp[i-1]-1) >= 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + ((i - dp[i-1] - 2) >= 0 ? dp[i - dp[i-1] - 2] : 0)  + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        
        return ans; 
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st; 
        st.push(-1);
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')  {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        
        return ans; 
    }
};
