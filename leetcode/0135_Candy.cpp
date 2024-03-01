class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> c(ratings.size(), 1);
        int ret = 0;

        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                c[i] = max(c[i], c[i - 1] + 1);
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                c[i] = max(c[i], c[i + 1] + 1);
            }
        }

        for (auto &cc : c) {
            ret += cc;
        }

        return ret;
    }
};
