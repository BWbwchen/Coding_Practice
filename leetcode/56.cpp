// faster than 75.52% solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        else if (intervals.size() == 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        int sl = intervals[0][0], sr = intervals[0][1];
        int nl, nr;
        vector<vector<int >> res;
        for (int i = 1; i < intervals.size(); ++i) {
            nl = intervals[i][0];
            nr = intervals[i][1];
            if (nl > sr) {
                res.push_back({sl, sr});
                sl = nl;
                sr = nr;
            } else {
                sr = max(nr, sr);
            }
        }
        res.push_back({sl, sr});
        return res;
    }
};
