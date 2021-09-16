class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int _k = k % nums.size();
        /*
        reverse(nums.begin(), nums.begin()+(int)nums.size());
        reverse(nums.begin(), nums.begin()+_k);
        reverse(nums.begin()+_k, nums.begin()+(int)nums.size());
        */
        my_reverse(nums, 0, (int)nums.size());
        my_reverse(nums, 0, _k);
        my_reverse(nums, _k, (int)nums.size());
    }
    
    void my_reverse(vector<int>& nums, int start, int end) {
        while((start != end) && (start != --end)) {
            swap(nums[start], nums[end]); 
            ++start;
        }
    }
};
