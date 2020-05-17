#include <vector>
#define DEBUG
#define MAXN 10000000
#define ll unsigned long long int
#include <bits/stdc++.h>
using namespace std;

bool zero = false;

ll minmax(ll a) {
    ll _min = 9, _max = 0;
    while (a) {
        if (a%10 < _min) _min = a%10;
        if (a%10 > _max) _max = a%10;
        a /= 10;
    }
    if (_min == 0 || _max == 0) zero = true;
    return _min * _max;
}
int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        ll a, k;
        cin >> a >> k;
        zero = false;
        for (ll i = 0; i < k-1; ++i) {
            //cout << "=====================" << endl;
            //cout << "add " << minmax(a) << endl;
            a += minmax(a);
            if (zero) break;
        }
        cout << a << endl;
        
    }

    return 0;
}
