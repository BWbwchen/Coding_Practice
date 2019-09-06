// https://codeforces.com/contest/1213/problem/D1
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

    int n, k;
    
    cin >> n >> k;
    
    vector<int > a;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }


    // guess target number
    vector<int > possible;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        while (x > 0) {
            possible.push_back(x);
            x/=2;
        }
    }


    // try divide
    int ans = MAXN;
    for (auto x : possible) {
        vector<int > cnt;
        for (int i = 0; i < n; ++i) {
            int y = a[i], count = 0;
            while (x < y) {
                y/=2;
                count++;
            }
            if (y == x ) cnt.push_back(count);
        }
        if (int(cnt.size() < k)) continue;
        sort(cnt.begin(), cnt.end());
        ans = min(ans, accumulate(cnt.begin(), cnt.begin()+k, 0));
    }



    cout << ans << endl;

    return 0;
}


