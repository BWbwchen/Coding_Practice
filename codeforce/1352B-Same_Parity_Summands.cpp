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


    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // all 1 with odd
        if ((n-k+1) > 0 && (n - k + 1) % 2 == 1) {
            cout << "YES" << endl;
            for (int i = 0; i < k-1; ++i) {
                cout << "1 ";
            }
            cout << n-k+1 << endl;
        // all 2 with even
        } else if ((n-2*k+2) > 0 && (n - 2*k + 2) % 2 == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < k-1; ++i) {
                cout << "2 ";
            }
            cout << n-2*k+2 << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }


    return 0;
}
