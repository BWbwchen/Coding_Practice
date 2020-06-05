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
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int _min = min (a, b), _max = max(a, b);

        int ans = min(max(2*_min, _max), _min+_max);
        cout << ans * ans << endl;
    }


    return 0;
}
