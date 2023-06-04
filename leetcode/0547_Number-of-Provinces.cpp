class Solution {
public:
    vector<vector<int>> map;
    vector<bool> done;
    void dfs(int j) {
        done[j] = true;
        for (int i = 0; i < map.size(); ++i) {
            if (map[i][j] && !done[i])
                dfs(i);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected) {
        int w = isConnected[0].size();
        int h = isConnected.size();

        map = isConnected;
        done = vector<bool>(h, false);


        int count = 0;
        for (int i = 0; i < h; ++i) {
            if (!done[i]) {
                // dfs
                dfs(i);
                count++;
            }
        }
        return count;
    }
};
