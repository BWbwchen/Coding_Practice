class Solution {
public:
    char convert(char c) {
        if (c == 'a')
            return 'z';
        return c - 1;
    }
    string smallestString(string s) {
        string answer = s;
        vector<int> dp(s.size(), 0);  // non-a consecutive string.
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                dp[i] = 0;
            } else {
                if (i == 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i - 1] + 1;
                }
            }
        }
        int start = -1;
        int end = -1;
        int len = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (len != 0 && dp[i] < len) {
                break;
            } else if (dp[i] > len) {
                len = dp[i];
                cout << i << ", " << dp[i] << endl;
                end = i;
                start = i - dp[i] + 1;
            }
        }
        if (len <= 0) {
            for (int i = s.size() - 1; i >= 0; ++i) {
                if (s[i] == 'a') {
                    answer[i] = convert(s[i]);
                    break;
                }
            }
            return answer;
        } else {
            for (int i = start; i <= end; ++i) {
                answer[i] = convert(s[i]);
            }
        }

        return answer;
    }
};
