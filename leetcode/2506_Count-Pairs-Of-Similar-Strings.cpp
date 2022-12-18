class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<int> m(words.size(), 0);
        int idx = 0;
        for (auto &s : words) {
            for (auto &c : s)
                m[idx] |= (1 << (c - 'a'));
            idx++;
        }
        int ans = 0;
        for (int i = 0; i < m.size(); ++i) {
            for (int j = i+1; j < m.size(); ++j) {
                if (m[i] == m[j])
                    ans++;
            }
        }
        return ans;
    }
};
