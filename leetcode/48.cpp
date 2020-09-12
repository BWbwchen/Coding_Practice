// faster than 100% solution ! Wow
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i+1; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // swap 
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size()/2; ++j) {
                swap(matrix[i][j], matrix[i][matrix.size()-1-j]);
            }
        }
    }
};
