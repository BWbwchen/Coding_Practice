// O(n) but faster than 96.48% solution ???
class Solution {
public:
    int search(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (target == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};


// Use binary search, O(logn) but much slower why ???
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                // start ~ mid is sorted
                if (target == nums[mid]) {
                    return mid;
                } else if (target > nums[mid] || target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            } else {
                // mid ~ end is sorted
                if (target == nums[mid]) {
                    return mid;
                } else if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
        }
        // return start
        if (nums[start] == target)
            return start;
        return -1;
    }
};

// Binary search with less search step
// Key point is to find which trend that target in. ascending part? or
// descending part?
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = -1;

        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[l] == target) {
                return l;
            } else if (nums[r] == target) {
                return r;
            } else if (nums[mid] > nums[r]) {
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target && target > nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target && target < nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
