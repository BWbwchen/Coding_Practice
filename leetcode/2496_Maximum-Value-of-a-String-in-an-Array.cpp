class Solution {
public:
    int solve(string s) {
        bool is_alpha = true;
        bool is_digit = true;
        
        for (auto &c : s) {
            is_alpha &= isalpha(c);
            is_digit &= isdigit(c);
        }
        
        if (is_alpha) {
            return s.length();
        }
        
        if (is_digit) {
            return stoi(s);
        }
        return s.length();
    }
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (auto &s : strs) {
            int a = solve(s); 
            ans = max(ans, a);
        }
        return ans;
    }
};
