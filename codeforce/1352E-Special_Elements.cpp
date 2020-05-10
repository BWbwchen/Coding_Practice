#define DEBUG
#define MAXN 10000000
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int total;
        cin >> total;
        vector<int> c(total, 0), cnt(8004, 0);

        // count the c[i]'s times
        for (int i = 0; i < total; ++i) {
            cin >> c[i];
            cnt[c[i]]++;
        }

        int ans = 0;
        // brute force all sum of interval
        // check whether there exist the item which is "sum"
        for (int l = 0; l < total; ++l) {
            int sum = c[l];
            for (int r = l+1; r < total; ++r) {
                sum += c[r];
                if (sum <= total) {
                    ans += cnt[sum];
                    cnt[sum] = 0;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
