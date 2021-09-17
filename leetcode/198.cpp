class Solution {
public:
    int rob(vector<int>& nums) {
        int take_prev = 0;
        int without_take_prev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] + without_take_prev > take_prev) {
                swap(without_take_prev, take_prev);
                take_prev += nums[i];
            } else {
                without_take_prev = max(take_prev, without_take_prev);
                take_prev = max(take_prev, without_take_prev);
            }
        }
        return max(take_prev, without_take_prev);
    }
};
