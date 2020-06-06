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

    int n ;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        vector<int > v(a, 0);
        for (auto &it : v) cin >> it;
        sort(v.begin(), v.end());
        int ans = MAXN;
        for (int i = 1; i < a; ++i) {
            ans = min (ans , v[i] - v[i-1]);
        }
        cout << ans << endl;
    }


    return 0;
}
