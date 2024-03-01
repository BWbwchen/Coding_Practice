class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;  // i for s and j for g.
        int ret = 0;
        while (i < s.size() && j < g.size()) {
            if (s[i] >= g[j]) {
                ret++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        return ret;
    }
};
