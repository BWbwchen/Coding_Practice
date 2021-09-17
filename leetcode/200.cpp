class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        
        int ans = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    findIslands(grid, row, col);
                    ans++;
                }
            }
        }
        return ans;
    }
    
    void findIslands(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1') {
            return; 
        }
        
        grid[row][col] = '-';
        findIslands(grid, row-1, col);
        findIslands(grid, row+1, col);
        findIslands(grid, row, col-1);
        findIslands(grid, row, col+1);
    }
};
