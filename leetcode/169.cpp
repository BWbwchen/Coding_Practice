class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore voting algorithm
        int count = 0, majority;
        for (auto n : nums) {
            if (!count) majority = n;
            count += (n == majority) ? 1 : -1;
        }
        return majority;
    }
};
