class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end(), greater<int>());   
        return nums[k-1];
    }
};
