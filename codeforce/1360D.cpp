#include <cstdio>
#include <vector>
#define DEBUG
#define MAXN 2000000000
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
    int t ; 
    cin >> t ;
    while (t--) {
        int n, k;
        cin >> n >> k;

        bool a = true;
        int ans = MAXN;
        //cout << "=================" << endl;
        for (int i = 1; i*i <= n; ++i) {
            if (n%i == 0) {
                if (n/i <= k) {
                    ans = min(ans, i);
                } else if (i <= k) {
                    ans = min(ans, n/i);
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}
