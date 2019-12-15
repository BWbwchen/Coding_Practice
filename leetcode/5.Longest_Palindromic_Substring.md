#Longest Palindromic Substring

##dp point : dp[start][end] means from index start to index end 's substring is a palindromic ? true or false
```cpp = class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        bool dp[s.length()][s.length()] = {{false}};
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = true;
            else
                dp[i][i + 1] = false;
        }

        for (int end = 2; end < s.length(); ++end) {
            for (int start = 0; start < end - 1; ++start) {
                if (dp[start + 1][end - 1] && (s[start] == s[end]))
                    dp[start][end] = true;
                else
                    dp[start][end] = false;
            }
        }

        int start = 1, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                if (dp[i][j]) {
                    if ((j - i + 1) > (end - start + 1)) {
                        start = i;
                        end = j;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};
```
