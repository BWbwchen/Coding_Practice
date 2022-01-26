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

    void bfs(vector<vector<char>>& grid, int ii, int jj) {
        queue<pair<int, int>> q;
        grid[ii][jj] = '#';
        q.push({ii, jj});
        
        while(!q.empty()) {
            auto top = q.front(); q.pop();
            
            int i = top.first;
            int j = top.second;
            
            
            if (i-1 >= 0 && grid[i-1][j] == '1') {
                grid[i-1][j] = '#';
                q.push({i-1, j});
            }
            if (i+1 < grid.size() && grid[i+1][j] == '1') {
                grid[i+1][j] = '#';
                q.push({i+1, j});
            }
            if (j-1 >= 0 && grid[i][j-1] == '1') {
                grid[i][j-1] = '#';
                q.push({i, j-1});
            }
            if (j+1 < grid[0].size() && grid[i][j+1] == '1') {
                grid[i][j+1] = '#';
                q.push({i, j+1});
            }
        }
    }
};
