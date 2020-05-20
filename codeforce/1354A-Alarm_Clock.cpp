#include <vector>
#define DEBUG
#define MAXN 10000000
#define ll long long int
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <= b) {
            cout << b << endl;
            continue;
        }

        if (d >= c) {
            if (a > b) {
                cout << -1 << endl;
                continue;
            }
        } else {
            ll total = (a - b) / (c - d) + (((a-b) % (c-d) == 0) ? 0 : 1);
            cout << b + c * total << endl;
        }

    }

    return 0;
}
