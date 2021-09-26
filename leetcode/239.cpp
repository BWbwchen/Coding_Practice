// Monotonic queue
// https://labuladong.gitbook.io/algo-en/v/master/shu-ju-jie-gou-xi-lie/shou-ba-shou-she-ji-shu-ju-jie-gou/dan-tiao-dui-lie
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                while(!q.empty() && (q.back() < nums[i])) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            } else {
                // push new
                while(!q.empty() && (q.back() < nums[i])) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
                
                // get max
                ans.push_back(q.front());
                
                // remove front element
                if (q.front() == nums[i-k+1]) q.pop_front();
            }
        }
        return ans; 
    }
};
