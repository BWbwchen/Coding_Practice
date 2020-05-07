#define DEBUG
#define MAXN 100
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> weights(n, 0);
    vector<int> value(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> value[i];
    }

    vector<vector<int>> dp(n, vector<int>(MAXN + 1, 0));

    /*
     * dp[i][j]
     * dp[how many item i can use][now limit]
     * limit from 0 ~ MAXN
     */

    // i item
    for (int i = 0; i < n; ++i) {
        // 0 ~ MAXN limit
        // 0 is all 0
        for (int j = 0; j < MAXN + 1; ++j) {
            if (i == 0) {
                dp[i][j] = (j - weights[i] >= 0) ? value[i] : 0;
                continue;
            }
            if (j - weights[i] >= 0) {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - weights[i]] + value[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 1][MAXN] << endl;

    return 0;
}
