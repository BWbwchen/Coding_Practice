class Solution {
public:
    int numberOfPoints(vector<vector<int>> &nums) {
        vector<bool> v(200, false);
        int me = 0;
        for (auto &vv : nums) {
            int start = vv[0];
            int end = vv[1];
            for (int i = start; i <= end; ++i) {
                v[i] = true;
            }
            me = max(me, end);
        }
        int ret = 0;
        for (int i = 1; i <= me; ++i) {
            if (v[i])
                ret++;
        }
        return ret;
    }
};
