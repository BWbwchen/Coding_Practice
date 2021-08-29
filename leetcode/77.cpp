// recursive
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 0 || n == 0) {
            return {};
        } else if (k == 1) {
            vector<vector<int>> ans;
            for (int i = 1; i <= n; ++i) {
                ans.push_back(vector<int>(1, i));
            }
            return ans;
        }
        vector<vector<int>> ans; 

        for (auto i : combine(n-1, k-1)) {
            i.push_back(n);
            ans.push_back(i);
        }
        for (auto i : combine(n-1, k)) {
            ans.push_back(i);
        }
        return ans;
    }
};
