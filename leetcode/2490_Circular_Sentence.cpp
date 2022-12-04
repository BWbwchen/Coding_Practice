class Solution {
public:
    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }
    bool isCircularSentence(string sentence) {
        vector<string> vs = split(sentence, " ");
        if (vs.size() == 1)
            return vs[0].front() == vs[0].back();
        
        for (int i = 0; i < vs.size()-1; ++i) {
            if (vs[i].back() != vs[i+1].front())
                return false;
        }
        return vs[vs.size()-1].back() == vs[0].front();
    }
};
