// #define DEBUG
#define MAXN 2000000000
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n, 0);
    for (auto &vv : v)
        cin >> vv;

    sort(v.begin(), v.end());


    int l = 0, r = v.size() - 1;
    int ans = 0;
    while (l < r) {
        if (v[l] + v[r] <= x) {
            ans++;
            l++;
            r--;
        } else {
            // v[l] + v[r] > x
            r--;
            ans++;
        }
    }

    cout << ans + (l == r ? 1 : 0) << endl;

    return 0;
}
