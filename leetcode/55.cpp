// awesome solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, i = 0;
        /*
         * calculate max id you can go
         * but remember where you are should be less than 
         * max id you could go
         */
        for (i = 0; i < nums.size() && i <= reach; ++i) {
            reach = max(reach, i + nums[i]);
        }
        return i == nums.size();
    }
};

// stupid and tle solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp 
        // dp [start][end] can reach
        return helper(0, nums.size()-1, nums);
        
    }
    
    bool helper(int start, int end, vector<int > nums) {
        if (start == end) {
            return true;
        } else if (start == end-1) {
            return nums[start] > 0;
        }
        
        bool res = false;
        // has middle
        for (int i = start + 1; i < end; ++i) {
            res |= (helper(start, i, nums) & helper(i, end, nums));
        }
        // just go
        res |= (nums[start] >= (end - start));
        return res;
    }
};
