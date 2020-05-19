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
    string s;
    cin >> s;
    if (s.size() > t) {
        for (int i = 0; i < t; ++i) {
            cout << s[i];
        }
        cout << "..." << endl;
    } else {
        cout << s << endl;
    }



    return 0;
}
