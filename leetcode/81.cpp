class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // binary search
        int left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) return true;
            
            //if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
            //    left++;
            //    right--;
            //} else 
            
            // mid in the first part
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                //right --;
                left ++;
            }
        }
        
        return false;
    }
};
