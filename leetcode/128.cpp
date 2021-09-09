class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        
        int ans = 0;
        for (int num : us) {
            // if num-1 is in the set, it means that num is part of some consecutive sequence. We don't need to calculate the sub-sequence!!
            if (us.find(num-1) == us.end()) {
                int startTarget = num;
                int currentLen = 1;

                while (us.find(startTarget+1) != us.end()) {
                    startTarget += 1; 
                    currentLen += 1;
                }

                ans = max(ans, currentLen);
            }
        }
        return ans;
    }
};
