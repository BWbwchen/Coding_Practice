// pure swap
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int zero = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && zero < 0)
                zero = i;
            if (nums[i] != 0 && zero >= 0) {
                swap(nums[i], nums[zero++]);
            }
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int pos = 0;
        for (auto n : nums) {
            if (n != 0)
                nums[pos++] = n;
        }
        while (pos < nums.size())
            nums[pos++] = 0;
    }
};
