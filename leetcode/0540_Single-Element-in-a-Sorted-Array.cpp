class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            mid = (mid >> 1) << 1;

            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }
};
