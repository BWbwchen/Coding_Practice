class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> block(9, vector<int>(9, 0));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                
                int needle = board[i][j] - '0' - 1;
                row[i][needle] += 1;
                col[j][needle] += 1;
                block[(i/3) * 3 + j/3][needle] += 1;
                
                if ((row[i][needle] > 1) || (col[j][needle] > 1) || (block[(i/3)*3 + j/3][needle] > 1)) return false;
            }
        }
        
        return true;
    }
};
