// https://codeforces.com/contest/1213/problem/B
#define DEBUG
#define MAXN 1e9+10
#include <bits/stdc++.h>
 


using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int t, temp;
    cin >> t;
    while (t--) {
        int days;
        cin >> days;
        vector<int > a;
        for (int i = 0; i < days; ++i) {
            cin >> temp;
            a.push_back(temp);
        }
        int ans = 0, min = a.back() ;
        // compare
        for (int i = days-2; i >= 0; --i) {
            if (a[i] < min ) {
                min = a[i];
            } else if (a[i] > min) {
                ans ++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}


