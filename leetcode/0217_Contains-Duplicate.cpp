class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> us;
        for (auto &n : nums) {
            if (us.count(n))
                return true;
            us.emplace(n);
        }
        return false;
    }
};
