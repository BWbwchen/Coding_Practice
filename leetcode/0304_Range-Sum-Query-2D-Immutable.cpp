class NumMatrix {
public:
    // 2D prefix sum
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix) {
        prefix = vector<vector<int>>(matrix.size() + 1,
                                     vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[i - 1].size(); ++j) {
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i][j - 1] +
                               prefix[i - 1][j] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] -
               prefix[row1][col2 + 1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
