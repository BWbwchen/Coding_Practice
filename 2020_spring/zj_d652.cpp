#include <cstdio>
#include <vector>
#define DEBUG
#define MAXN 10000000
#define MULTIPLE(i, j, k) lake[i] * lake[j] * lake[k]
#include <bits/stdc++.h>
using namespace std;

/*
int solve(vector<int> lake) {
    if (lake.size() == 3) {
        return lake[0] * lake[1] * lake[2];
    } else if (lake.size() < 3) {
        return 0;
    }

    int ans = MAXN;
    for (int i = 1; i < lake.size() - 1; ++i) {
        // remove No.i item
        int removed_item = lake[i];
        lake.erase(lake.begin() + i);
        ans = min(ans, lake[i-1] * removed_item * lake[i] + solve(lake));
        // put back
        lake.insert(lake.begin() + i, removed_item);
    }
    return ans;
}
*/

int solve(vector<int> lake, int n) {
    vector<vector<int>> dp(n, vector<int>(n, MAXN));

    // init
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
        if (i != n - 1) dp[i][i + 1] = 0;
    }

    for (int i = 1; i < n - 1; ++i) {
        dp[i - 1][i + 1] = MULTIPLE(i - 1, i, i + 1);
    }

    /*
     * NOTICE 
     * the order of for loop
     * and the "start" should count in reverse order
     */
    for (int end = 2; end < n; ++end) {
        for (int start = end - 2; start >= 0; --start) {
            for (int middle = end - 1; middle >= start + 1; --middle) {
                dp[start][end] =
                    min(dp[start][end], dp[start][middle] + dp[middle][end] +
                                            MULTIPLE(start, middle, end));
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> lake(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> lake[i];
    }

    cout << solve(lake, n) << endl;

    return 0;
}

/*
 * DP METHOD
 * dp[i][j] : merge item from i to j will cost dp[i][j]
 * dp[i][j] = min(dp[i][k] + dp[k][j] + [i]*[k][j]),
 * where k from i to j
 * dp[i][i] = 0
 * dp[i][i+1] = 0
 * dp[i-1][i+1] = [i-1] * [i] * [i+1]
 */

/*
 * BRUTE FORCE METHOD (recursive)
 * function solve(array)
 * if size == 3
 *      return [0] * [1] * [2]
 * if size < 3
 *      return 0
 *
 * ans = MAXN
 * for i from 1 to size-2 do
 *      remove No.i item from array
 *      NOTICE !!! this notice i-1 i i+1 should be i-1 removed_item i
 *      ans = min(ans, [i-1]*[i]*[i+1]+solve(array))
 *      put back No.i item to array
 *
 * return ans
 */
