class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> point;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    point.push_back(make_pair(i, j));
                }
            }
        }
        
        for (auto p : point) {
            int row = p.first;
            int col = p.second;
            // row
            for (int i = 0; i < matrix[0].size(); ++i) {
                matrix[row][i] = 0; 
            }
            // col
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][col] = 0; 
            }
        }
    }
};
