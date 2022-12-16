// build a prime table
class Solution {
public:
    int countPrimes(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 0;

        vector<bool> t(n, true);
        t[0] = false;
        t[1] = false;

        for (int i = 2; i <= (int) sqrt(n); ++i) {
            if (t[i] == false)
                continue;
            for (int j = 2 * i; j < n; j += i) {
                t[j] = false;
            }
        }

        int ans = 0;
        for (auto b : t) {
            if (b)
                ans++;
        }
        return ans;
    }
};
