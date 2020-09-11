// recursive, faster than 12.93% solution
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int >> res;
        vector<int > now;
        find(0, target, now, candidates, res);
        return res;
    }
    
    void find (
        int c_id, 
        int target, 
        vector<int > now, 
        vector<int> candidates, 
        vector<vector<int >>& res) 
    {
        if (target == 0) {
            res.push_back(now);
            return;
        }
        if (c_id == candidates.size()) return;
        // use next c_id
        find(c_id+1, target, now, candidates, res);
        
        // use same c_id
        if (target - candidates[c_id]>= 0) {
            now.push_back(candidates[c_id]);
            find(c_id, target-candidates[c_id], now, candidates, res);
        }
        
    }
};
