class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row_start = 0;
        int col_start = 0; 
        int row_end = matrix.size()-1;
        int col_end = matrix[0].size()-1;
        
        while (true) {
            
            // row (right)
            for (int i = col_start; i <= col_end; ++i) {
                ans.push_back(matrix[row_start][i]); 
            }
            row_start++;
            
            if (!valid(row_start, row_end, col_start, col_end)) break;
            
            // col (down)
            for (int i = row_start; i <= row_end; ++i) {
                ans.push_back(matrix[i][col_end]); 
            }
            col_end--;
            
            if (!valid(row_start, row_end, col_start, col_end)) break;
            
            // row (left)
            for (int i = col_end; i >= col_start; --i) {
                ans.push_back(matrix[row_end][i]); 
            }
            row_end--;
            
            if (!valid(row_start, row_end, col_start, col_end)) break;
            
            // col (up)
            for (int i = row_end; i >= row_start; --i) {
                ans.push_back(matrix[i][col_start]); 
            }
            col_start++;
            
            if (!valid(row_start, row_end, col_start, col_end)) break;
        }
        
        return ans;
    }
    
    bool valid(int row_start, int row_end, int col_start, int col_end) {
        return row_start <= row_end && col_start <= col_end;
    }
};
