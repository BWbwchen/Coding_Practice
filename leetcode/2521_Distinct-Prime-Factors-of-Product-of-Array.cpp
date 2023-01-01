class Solution {
public:
    int distinctPrimeFactors(vector<int> &nums) {
        unordered_set<int> ret;
        for (auto &n : nums) {
            int pc = 2;
            while (n > 1) {
                if (n % pc == 0) {
                    ret.insert(pc);
                    n /= pc;
                } else {
                    pc++;
                }
            }
        }
        return ret.size();
    }
};
