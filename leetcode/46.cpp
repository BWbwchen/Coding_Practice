// faster than 88.09% solution
// fixed a item and permute the remain
class Solution {
public:
    vector<vector<int >> res;
    vector<vector<int>> permute(vector<int>& nums) {
        
        helper(0, nums);
        return res;
    }
    void helper (int start, vector<int > nums) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            helper(start+1, nums);
            swap(nums[i], nums[start]);
        }
        
    }
};
