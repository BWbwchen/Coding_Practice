class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (auto &s : columnTitle) {
            ans *= 26;
            ans += (s - 'A') + 1;
        }
        return ans;
    }
};
