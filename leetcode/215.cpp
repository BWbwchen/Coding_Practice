class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end(), greater<int>());   
        return nums[k-1];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (auto v : nums) {
            q.push(v);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }
};
