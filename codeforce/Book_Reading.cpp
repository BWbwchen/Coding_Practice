// https://codeforces.com/contest/1213/problem/C
#define DEBUG
#define MAXN 1e9+10
#include <bits/stdc++.h>
 
#define LONG unsigned long long int 

using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int t;
    LONG n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        LONG times = n/m;
        LONG ans = 0;
        // remain 
        for (LONG i = 1; i <= times%10; ++i) {
            ans += (i*(m%10))%10;
        }
        // cycle
        LONG cycle = 0;
        for (LONG i = 1; i <= 10; ++i) {
            cycle += (i*(m%10))%10;
        }
        ans += cycle*(times/10);
        cout << ans << endl;
    }
    
    return 0;
}


