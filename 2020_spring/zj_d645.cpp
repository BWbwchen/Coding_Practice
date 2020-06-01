#include <cstdio>
#include <vector>
#define DEBUG
#define MAXN 10000000
#define MULTIPLE(i, j, k) lake[i] * lake[j] * lake[k]
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int > dp(1005, 0);
    /*
     * dp[i] = the max value when the limit is i
     * when input new food
     * we try to take all of it
     * dp[i] = max(dp[i], value + dp[i-weight]
     */
    while (n--) {
        int value, weight, num;
        cin >> value >> weight >> num;
        // take much you can take
        if (num == -1) num = w/weight + 1;
        for (int i = 0; i < num; ++i) {
            // Notice !! need reverse !!
            // Because if the num == 1, the forward will take it multiple time
            // reverse Ex: num = 1, weight = 2, value = 5
            // dp[2] take it , dp[3] take ..... all take it (but the num = 1)!
            // forward Ex: num = 1, weight = 2, value = 5
            // dp[w] take it, but dp[w-weight] doesn't take it!
            //for (int j = weight; j <= w; ++j) {
            for (int j = w; j >= weight; --j) {
                dp[j] = max(dp[j], value+dp[j-weight]);
            }
        }
    }
    int ans = -MAXN;
    for (int i = 1; i <= w; ++i) ans = max(ans, dp[i]);

    cout << ans << endl;


    return 0;
}
