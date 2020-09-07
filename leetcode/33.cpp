// O(n) but faster than 96.48% solution ???
class Solution {
public:
    int search(vector<int>& nums, int target) {
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
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid;
        while (start < end) {
            mid = start + (end - start)/2;
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
        if (nums[start] == target) return start;
        return -1;
    }
};
