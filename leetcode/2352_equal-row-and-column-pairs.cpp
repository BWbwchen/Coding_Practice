#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>, int> row_cnt;
        for (auto &v : grid) {
            row_cnt[v]++;
        }

        // for the search part, we can use map to boost the search speed.
        vector<int> col(n);
        for (int i = 0; i < n; ++i) {
            // for each column, check whether it is in the row_cnt
            for (int j = 0; j < n; ++j)
                col[j] = grid[j][i];

            count += row_cnt[col];
        }
        return count;
    }
};

// O(n ^ 3)
class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // compare row i with col j
            for (int j = 0; j < n; ++j) {
                bool same = true;
                for (int k = 0; k < n; ++k) {
                    same &= (grid[i][k] == grid[k][j]);
                }
                if (same) {
                    count++;
                }
            }
        }
        return count;
    }
};
