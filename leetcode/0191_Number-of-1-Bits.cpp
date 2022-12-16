class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            if (n & 1)
                ans++;
            n >>= 1;
        }
        return ans;
    }
};
