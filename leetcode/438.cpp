class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> smap(26, 0);
        vector<int> pmap(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            smap[s[i] - 'a'] ++;
            pmap[p[i] - 'a'] ++;
        }
        vector<int> ret;
        if (smap == pmap) ret.push_back(0);
        for (int i = 0; i < (s.size() - p.size()); ++i) {
             smap[s[i] - 'a']--;
             smap[s[i+p.size()] - 'a']++;
             if (smap == pmap) ret.push_back(i+1);
        }
        return ret;
    }
};
