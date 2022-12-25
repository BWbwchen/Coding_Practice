class Solution {
public:
    vector<string> tokenize(string const &str) {
        vector<string> out;
        // construct a stream from the string
        std::stringstream ss(str);

        std::string s;
        while (std::getline(ss, s, ' ')) {
            out.push_back(s);
        }
        return out;
    }
    int score(unordered_set<string> &positive_feedback,
              unordered_set<string> &negative_feedback, string comment) {
        auto ss = tokenize(comment);
        int ret = 0;
        for (auto &s : ss) {
            if (positive_feedback.count(s) > 0)
                ret += 3;
            if (negative_feedback.count(s) > 0)
                ret -= 1;
        }
        return ret;
    }
    vector<int> topStudents(vector<string> &positive_feedback,
                            vector<string> &negative_feedback,
                            vector<string> &report, vector<int> &student_id,
                            int k) {
        unordered_set<string> pf(positive_feedback.begin(),
                                 positive_feedback.end());
        unordered_set<string> nf(negative_feedback.begin(),
                                 negative_feedback.end());


        vector<int> ret;
        unordered_map<int, int> id_to_score;
        for (int i = 0; i < report.size(); ++i) {
            int sc = score(pf, nf, report[i]);
            ret.emplace_back(sc);
            id_to_score[student_id[i]] = sc;
        }

        sort(student_id.begin(), student_id.end(),
             [&](const int &id_l, const int &id_r) {
                 if (id_to_score[id_l] > id_to_score[id_r]) {
                     return true;
                 } else if (id_to_score[id_l] == id_to_score[id_r]) {
                     return id_l < id_r;
                 }
                 return false;
             });

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(student_id[i]);
        }

        return ans;
    }
};
