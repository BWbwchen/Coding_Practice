class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& gg: grid)
            sort(gg.begin(), gg.end(), greater<int>());
        
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < col; ++i) {
            int tmp = 0;
           for (int j = 0; j < row; ++j) {
                tmp = max(tmp, grid[j][i]); 
           } 
            ans += tmp;     
        }
        return ans;
    }
};
