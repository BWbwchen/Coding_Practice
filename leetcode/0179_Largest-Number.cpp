class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &l, const int &r) {
            // sort by string format.
            return to_string(l) + to_string(r) > to_string(r) + to_string(l);
        });

        string ans;
        for (auto &n : nums) {
            if (ans == "" && n == 0)
                continue;
            ans += to_string(n);
        }
        if (ans == "")
            return "0";
        return ans;
    }
};
