// O(n) with space O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        for (auto n : nums) {
            if (v[n] != 0) {
                return n;
            }
            v[n] += 1;
        }
        return -1;
    }
};

// hashMap
// O(n) with space O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            auto got = m.find(n);
            if (got != m.end()) {
                return n;
            }
            m[n] = 1;
        }
        return -1;
    }
};

// Floyd's tortoise and hare
// O(n) with space O(1)
// same as detect linked list cycle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; 
        int fast = nums[0]; 
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        int begin = nums[0];
        while(begin != slow) {
            slow = nums[slow];
            begin = nums[begin];
        }
        return begin;
    }
};
