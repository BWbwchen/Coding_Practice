class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // step 1 : find Inflection point
        int InflectionPoint = -1;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                InflectionPoint = i - 1; 
                break;
            }
        }
        
        if (InflectionPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // step 2 : swap it with the similar point of the remain part
        int diffPoint = InflectionPoint;
        for (int i = InflectionPoint + 1; i < nums.size(); ++i) {
            if (nums[InflectionPoint] < nums[i]) {
                diffPoint = i;
            }
        }
        
        // step 3 : swap inflectionPoint and diffpoint
        int temp = nums[diffPoint];
        nums[diffPoint] = nums[InflectionPoint];
        nums[InflectionPoint] = temp;
        
        // step 4 : swap the remaining part
        reverse(nums.begin() + InflectionPoint + 1, nums.end());
    }
};
