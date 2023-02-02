class Solution {
public:
    const long long int mod = 1e9 + 7;
    // a^b
    long long int binpow(long long int a, long long int b) {
        long long int res = 1;
        while (b > 0) {
            if (b & 1)
                res *= a;
            a *= a;
            res = res % mod;
            a = a % mod;
            b >>= 1;
        }
        return res;
    }
    int monkeyMove(int n) {
        // 2^n - 2
        long long int bp = binpow(2, n);
        long long int ans = bp - 2;
        if (ans < 0) {
            return ans + mod;
        }
        return ans;
    }
};
