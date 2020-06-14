//#define DEBUG
#define MAXN 2000000000
#define ll unsigned long long int
#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    ll ans = (n+1)*n/2;
 
    for (int i = 0; i < n-1; ++i) {
        ll t;
        cin >> t;
        ans -= t;
    }
    cout << ans << endl;
 
 
 
 
    return 0;
}
