#define DEBUG
#define MAXN 100000010
#include <bits/stdc++.h>
using namespace std;


int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<pair <int , int >> v;
        v.push_back(make_pair(s[0]-'0', 1));
        for (int i = 1; i < s.size(); ++i) {
            if (s[i]-'0' != v.back().first ) {
                v.push_back(make_pair(s[i]-'0', 1));
            } else {
                v.back().second ++ ;
            }
        }
        if (v.size() < 3) {
            cout << 0 << endl;
            continue;
        }
        int ans = MAXN;
        for (int i = 1; i < v.size()-1 ; ++i)  {
            if (v[i-1].first != v[i+1].first) {
                ans = min(ans, v[i].second+2);
            }
        }
        if (ans == MAXN) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }
    



    return 0;
}
