#define DEBUG
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

    int n;
    ll a, b, x, y, l;
    cin >> n;
    while (n--) {
        cin >> a >> b >> x >> y >> l;


        // decrease a then b
        ll _a = a, _b = b, _l = l;
        if (_a-x <= _l) {
            _l -= _a-x;
            _a = x;
        } else {
            _a -= _l;
            _l = 0;
        }
        if (_b - y  <= _l) {
            _l -= _b - y;
            _b = y;
        } else {
            _b -= _l;
            _l = 0;
        }
        ll ans1 = _a * _b;
        // decrease b then a
        _a = a; _b = b; _l = l;
        
        if (_b - y  <= _l) {
            _l -= _b - y;
            _b = y;
        } else {
            _b -= _l;
            _l = 0;
        }
        if (_a-x <= _l) {
            _l -= _a-x;
            _a = x;
        } else {
            _a -= _l;
            _l = 0;
        }
        
        
        ll ans2 = _a * _b;

        
        cout << min(ans1, ans2) << endl;

    }




    return 0;
}
