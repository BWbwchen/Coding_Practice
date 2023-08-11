class Solution {
public:
    using vn = vector<int>;

    bool equal(vn &nums, int mid) {
        bool minus_1_ok = (mid == 0) ? true : nums[mid - 1] < nums[mid];
        bool plus_1_ok =
            (mid == nums.size() - 1) ? true : nums[mid] > nums[mid + 1];
        return minus_1_ok && plus_1_ok;
    }

    bool is_increment(vn &nums, int mid) {
        bool minus_1_ok = (mid == 0) ? true : nums[mid - 1] < nums[mid];
        bool plus_1_ok =
            (mid == nums.size() - 1) ? true : nums[mid] < nums[mid + 1];
        return minus_1_ok && plus_1_ok;
    }

    int findPeakElement(vector<int> &nums) {
        // binary search
        // write our own compare function

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (equal(nums, mid)) {
                return mid;
            } else if (is_increment(nums, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};
