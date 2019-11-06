// https://codeforces.com/contest/1213/problem/A
#define DEBUG
#define MAXN 1e9+10
#include <bits/stdc++.h>
 
/*
    think about this :
    all number can move +/-2 to 2, or move +/- to 1.
*/

using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int total, temp, odd = 0, even = 0;
    cin >> total;
    for (int i = 0; i < total; ++i) {
        cin >> temp;
        if (temp % 2) odd++;
        else even++;
    }
    cout << min(odd, even) << endl;
    
    return 0;
}


