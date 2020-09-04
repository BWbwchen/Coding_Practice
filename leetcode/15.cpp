// faster than 93.29% solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        sort(nums.begin(), nums.end());
        
        vector<vector<int >> ans;
        int i = 0;
        while (i < nums.size()) {
            int goal = -nums[i];
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                if (nums[l] + nums[r] < goal) {
                    l ++;
                } else if (nums[l] + nums[r] > goal) {
                    r--;
                } else {
                    vector<int > temp = {nums[i], nums[l], nums[r]};
                    ans.push_back(temp);
                    l++;
                    r--;
                    while (l < r && nums[l-1] == nums[l]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
            }
            i++;
            while (i < nums.size() && nums[i-1] == nums[i]) i++;
        }
        return ans;
        
    }
};


