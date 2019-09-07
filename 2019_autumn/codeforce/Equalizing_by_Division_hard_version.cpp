// https://codeforces.com/contest/1213/problem/D2
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

    // let val[x][i] be a_i divide val[x][i] times of 2 will obtain x
    // so array val[x] will not consider who can obtain x, it consider how many number 'can' obtain x

    vector<vector<int > > val(200000+10);
    for (int i = 0; i < n; ++i) {
        int x = a[i], count = 0;
        while (x > 0) {
            val[x].push_back(count++);
            x/=2;
        }
    }


    int ans = MAXN;
    for (int i = 0; i < 200000+10; ++i) {
        if(int(val[i].size()) < k) continue; 
        sort(val[i].begin(), val[i].end());
        ans = min(ans, accumulate(val[i].begin(), val[i].begin()+k, 0));
    }


    cout << ans << endl;

    return 0;
}


