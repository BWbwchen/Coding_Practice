// space complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string ss = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (ss == "")
                    continue;
                else {
                    vs.push_back(ss);
                    ss = "";
                }
            } else {
                ss.push_back(s[i]);
            }
        }
        if (ss != "")
            vs.push_back(ss);

        reverse(vs.begin(), vs.end());
        string ret = "";
        for (auto &sss : vs) {
            ret += sss + " ";
        }
        ret.erase(ret.size() - 1, ret.size() - 1);
        return ret;
    }
};
