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

    string s, t;
    cin >> s >> t;

    string test = t.substr(0, s.size());
    if (test == s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    


    return 0;
}
