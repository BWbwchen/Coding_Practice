#include <cstdio>
#include <vector>
#define DEBUG
#define MAXN 10000000
#define MULTIPLE(i, j, k) lake[i] * lake[j] * lake[k]
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
     * 1 -> (0L: 1)
     * 2 -> (1L: 4) + (0L: 1)                                       = 1L + f(1)
     * 3 -> 2*(1L: 4) + (0L: 1)                                     = 1L + f(2)
     * 4 -> (2L: 4*4) + 3*(1L: 4) + (0L:1)                          = 2L + 1L + f(3)
     * 5 -> 3*(2L: 4*4) + 4*(1L:4) + (0L:1)                         = 2*2L + 1L + f(4)
     * 6 -> (3L:4*4*4) + 4!/2! * (2L: 4*4) + 5!/4!(1L:4) + (0L:1)   = *2L
     * n -> (n/2L: 4^(n/2)) + (n/2 - 1L:)
     */
    /*
     * No 0L
     * 2 -> 1L
     * 3 -> 1L 3-(1*2)
     * 4 -> 2L 4-(2*2)
     * 5 -> 2L 5-(2*2)
     * 6 -> 3L
     */
    /*
     * dp[n] = (dp[n-1]*1) + (dp[n-2]*4) + (dp[n-3]*2)
     *          2 point    or  1 L       or 2 L
     */
    int n;
    cin >> n;

    vector<ll> dp(41, 0);
    dp[0] = 1LL;
    dp[1] = 1LL;
    dp[2] = 5LL;
    for (int i = 3; i <= 40; ++i) {
        dp[i] = (dp[i-1]) + 4*(dp[i-2]) + 2*(dp[i-3]);
    }
    while (n--) {
        int width;
        cin >> width;
        cout << dp[width] << endl;
    }

    return 0;
}
