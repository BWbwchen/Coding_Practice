class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string tmp;
        vector<string> vs;
        while (ss >> tmp)
            vs.emplace_back(tmp);

        if (vs.size() != pattern.size())
            return false;
        unordered_map<char, string> m;
        unordered_map<string, char> mm;
        for (int i = 0; i < pattern.size(); ++i) {
            int m_find = m.count(pattern[i]);
            int mm_find = mm.count(vs[i]);

            if (m_find <= 0 && mm_find <= 0) {
                m[pattern[i]] = vs[i];
                mm[vs[i]] = pattern[i];
            } else if (m_find > 0 && mm_find > 0) {
                if (m[pattern[i]] == vs[i] && mm[vs[i]] == pattern[i])
                    continue;
                return false;
            } else {
                return false;
            }
        }
        return true;
    }
};
