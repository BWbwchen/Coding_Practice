// O(1) space complexity method
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        // col -> matrix[i][0] have 0?
        // row -> matrix[0][j] have 0?
        bool col = false, row = false;

        // if a row should be all 0, we can record this thing at the
        // matrix[i][0]
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        row = true;
                    if (j == 0)
                        col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (row) {
            for (int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        }
        if (col) {
            for (int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
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
