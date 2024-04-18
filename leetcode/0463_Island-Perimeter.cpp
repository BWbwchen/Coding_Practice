class Solution {
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> ops;
    int island;
    int neigh;
    int max_i;
    int max_j;
    int islandPerimeter(vector<vector<int>>& grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        max_i = grid.size();
        max_j = grid[0].size();
        island = 0;
        neigh = 0;
        ops = {
            make_pair(-1, 0),
            make_pair(1, 0),
            make_pair(0, -1),
            make_pair(0, 1),
        };
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!visited[i][j])
                    bfs(grid, i, j);
            }
        }
        cout << "island: " << island << ", neigh: " << neigh << endl;
        return island * 4 - neigh;
    }
    bool legal(int i, int j) {
        return i >= 0 && i < max_i && j >= 0 && j < max_j;
    }
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if (legal(top.first, top.second) && !visited[top.first][top.second]) {
                visited[top.first][top.second] = true;
                if (grid[top.first][top.second]) {
                    island++;
                    for (auto op: ops) {
                        int new_i = top.first + op.first;
                        int new_j = top.second + op.second;
                        if (legal(new_i, new_j)) {
                            cout << new_i << ", " << new_j << endl;
                            q.push(make_pair(new_i, new_j));
                            if (grid[new_i][new_j])
                                neigh++;
                        }
                    }
                }
            }
        }
    }
};
