class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> v(26, 0);
        for (auto &c : s)
            v[c - 'a']++;

        for (auto &c : t) {
            if (v[c - 'a'] == 0)
                return false;
            v[c - 'a']--;
        }
        return true;
    }
};
