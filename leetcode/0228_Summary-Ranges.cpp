class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ret;
        int prev_start = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                if (nums.size() >= 2) {
                    if (nums[i] == (nums[i + 1] - 1)) {
                        // do nothing
                        prev_start = nums[i];
                    } else {
                        ret.push_back(to_string(nums[i]));
                        prev_start = nums[i + 1];
                    }
                } else {
                    ret.push_back(to_string(nums[i]));
                }
            } else if (i == nums.size() - 1) {
                if (prev_start == nums[i]) {
                    ret.push_back(to_string(prev_start));
                } else {
                    ret.push_back(to_string(prev_start) + "->" +
                                  to_string(nums[i]));
                }
            } else {
                if (nums[i] == (nums[i + 1] - 1)) {
                    // do nothing
                } else {
                    if (prev_start == nums[i]) {
                        ret.push_back(to_string(prev_start));
                    } else {
                        ret.push_back(to_string(prev_start) + "->" +
                                      to_string(nums[i]));
                    }
                    prev_start = nums[i + 1];
                }
            }
        }

        return ret;
    }
};
