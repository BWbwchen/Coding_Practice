class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(exist(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char >>& board, int i, int j, string word, int wid) {
        if (wid == word.size()) return true;
        // out of range
        if (i >= board.size() || j >= board[i].size() || 
            i < 0 || j < 0 ) return false;
        
        // check word
        if (board[i][j] != word[wid]) return false;
        
        // prevent check again
        board[i][j] ^= 255;
        
        bool res = exist(board, i, j+1, word, wid+1) ||
                   exist(board, i, j-1, word, wid+1) ||
                   exist(board, i+1, j, word, wid+1) ||
                   exist(board, i-1, j, word, wid+1);
        
        board[i][j] ^= 255;

        return res;
    }
};
