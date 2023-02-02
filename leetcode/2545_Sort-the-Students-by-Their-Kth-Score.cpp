class Solution {
public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
    sort(score.begin(), score.end(),
         [&](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[k] > rhs[k];
         });
    return score;
  }
};
