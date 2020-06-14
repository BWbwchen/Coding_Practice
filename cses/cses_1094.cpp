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
 
    
    int n;
    cin >> n;
    vector<ll > v(n, 0);
    for (auto &it : v) cin >> it;
 
    ll ans = 0;
    for (int i = 1; i < v.size(); ++i){
        if (v[i] < v[i-1]) {
            ans += v[i-1] - v[i];
            v[i] = v[i-1];
        }
    }
    cout << ans << endl;
 
 
    return 0;
}
