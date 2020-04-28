#define DEBUG
#include <bits/stdc++.h>
#define MAXN 1002
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    int v, w;
    cin >> m >> n;

    bitset<MAXN> mp[MAXN];
    set <pair<int, int>> s;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        cin >> v >> w;
        // multiple edge or self loop
        if (s.find(make_pair(v, w)) != s.end() || s.find(make_pair(w, v)) != s.end()|| v == w) {
            cout << "Yes" << endl;
            ok = false;
            break;
        }
        s.insert(make_pair(v,w));
        s.insert(make_pair(w,v));
    }
    if (ok) cout << "yes" << endl;
    


    return 0;
}
