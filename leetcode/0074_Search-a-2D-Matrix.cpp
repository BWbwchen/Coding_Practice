class Solution {
public:
    inline int row(int x, int n_col) { return x / n_col; }
    inline int col(int x, int n_col) { return x % n_col; }
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();

        int l = 0, r = n_row * n_col - 1;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int n_mid = matrix[row(mid, n_col)][col(mid, n_col)];
            if (n_mid == target) {
                return true;
            } else if (n_mid < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
