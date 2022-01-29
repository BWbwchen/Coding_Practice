class Solution {
public:
    static long long dist(const vector<int>& v) {
        return v[0] * v[0] + v[1] * v[1];
    }
    static bool mycmp(const vector<int>& lhs, const vector<int>&rhs) {
        return dist(lhs) < dist(rhs); 
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), mycmp); 
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
