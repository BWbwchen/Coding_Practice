class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.count(target - nums[i])) {
                return {um[target - nums[i]], i};
            }
            um[nums[i]] = i;
        }
        return {};
    }
};
