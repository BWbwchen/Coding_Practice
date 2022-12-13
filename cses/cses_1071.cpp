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

    ll n;
    ll r, c;
    cin >> n;
    while (n--) {
        cin >> r >> c;
        r--;
        c--;

        if (r > c) {
            if (r % 2 == 0) {
                cout << r * r + c + 1 << endl;
            } else {
                cout << (r + 1) * (r + 1) - c << endl;
            }
        } else {
            if (c % 2 == 0) {
                cout << (c + 1) * (c + 1) - r << endl;
            } else {
                cout << c * c + r + 1 << endl;
            }
        }
    }

    return 0;
}
