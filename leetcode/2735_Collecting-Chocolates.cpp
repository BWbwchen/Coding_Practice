// 1D DP
class Solution {
    using ll = long long;
    const ll MAXN = numeric_limits<ll>::max();

public:
    long long minCost(vector<int> &nums, int x) {
        // We will use DP.
        // dp[element id] = minimum cost to buy element id for some rotate nr
        int n = nums.size();
        vector<ll> dp(n, MAXN);

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
            ans += nums[i];
        }


        // i for rotate nr
        for (int i = 1; i < n; ++i) {
            ll tmp = 0;
            for (int j = 0; j < n; ++j) {
                // don't need rotate or need rotate
                dp[j] = min(dp[j], (ll) nums[(i + j) % n]);
                tmp += dp[j];
            }
            ans = min(ans, tmp + 1LL * (ll) i * (ll) x);
        }

        return ans;
    }
};
// 2D DP
class Solution {
    using ll = long long;
    const ll MAXN = numeric_limits<ll>::max();

public:
    long long minCost(vector<int> &nums, int x) {
        // We will use DP.
        // dp[element id][rotate number] = minimum cost to buy element id
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(n, MAXN));

        // The goal is to find how many rotate do we need to perform.
        // dp[element id][max rorate number] = minimum cost to buy element id
        for (int i = 0; i < n; ++i) {
            dp[i][0] = (ll) nums[i];
            for (int j = 1; j < n; ++j) {
                // don't need rotate or need rotate
                dp[i][j] = min(dp[i][j - 1], (ll) nums[(i + j) % n]);
            }
        }

        ll ans = MAXN;
        for (int i = 0; i < n; ++i) {
            ll tmp = 0;
            // for each maximum rotate number, find the corresponding cost.
            for (int j = 0; j < n; ++j) {
                tmp += dp[j][i];
            }
            ans = min(ans, tmp + 1LL * (ll) i * (ll) x);
        }
        return ans;
    }
};
