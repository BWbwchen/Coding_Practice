#include <vector>
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
    
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ans = 0;

    if (a >= k) {
        ans = k;
        cout << ans << endl;
    } else {
        ans += a;
        k -= a;
        if (b >= k) {
            cout << ans << endl;
        } else {
            k -= b;
            if (c >= k) {
                ans -= k;
                cout << ans << endl;
            }
        }
    }



    /*
    if ((a-k) >= 0) {
        ans += a;
        k -= a;
    }
    if ((k-b) >= 0) {
        k -= b;
    }
    if (k >= 0) {
        ans -= k;
    }
    cout << ans << endl;
    */


    return 0;
}
