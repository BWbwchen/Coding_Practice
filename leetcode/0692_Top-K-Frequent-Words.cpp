class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> um;
        for (auto &s : words) {
            um[s]++;
        }

        vector<string> vs;
        for (auto &np : um) {
            vs.emplace_back(np.first);
        }

        sort(vs.begin(), vs.end(), [&](const string &lhs, const string &rhs) {
            if (um[lhs] == um[rhs]) {
                return lhs < rhs;
            } else {
                return um[lhs] > um[rhs];
            }
        });

        vs.erase(vs.begin() + k, vs.end());
        return vs;
    }
};
