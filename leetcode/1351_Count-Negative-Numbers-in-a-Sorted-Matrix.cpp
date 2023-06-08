// O(n+m) method
class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int ret = 0;
        int row = grid.size();
        int col = grid[0].size();

        int i = 0;
        int j = col - 1;

        while (i < row && j >= 0) {
            if (grid[i][j] < 0) {
                ret += row - i;
                j--;
            } else {
                i++;
            }
        }

        return ret;
    }
};
// intuitive method
class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ret = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] < 0) {
                    ret += col - j;
                    break;
                }
            }
        }
        return ret;
    }
};

// Use binary search
class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int ret = 0;
        for (auto &row : grid) {
            auto tag = upper_bound(row.rbegin(), row.rend(), -1);
            ret += distance(row.rbegin(), tag);
        }
        return ret;
    }
};
