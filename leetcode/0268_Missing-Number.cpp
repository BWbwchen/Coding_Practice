// XOR method
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i)
            ans ^= (i ^ nums[i]);
        return ans;
    }
};


// sum method
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int ans = nums.size();
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            ans += i;
        }
        return ans - total;
    }
};
