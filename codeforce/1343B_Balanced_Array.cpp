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
        int n;
        cin >> n;
        if ((n/2)%2 == 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        // even
        for (int i = 0; i < n/4; ++i) {
            if (i % 2 == 0) {
                if (i != 0) {
                    cout << i << 2 << " " << i << 8 << " ";
                } else {
                    cout <<  2 << " " << 8 << " ";
                }
            } else {
                if (i != 1) {
                    cout << (i-1)/2 << 4 << " " << (i-1)/2 << 6 << " ";
                } else {
                    cout << 4 << " " << 6 << " ";
                }
            }
        }

        // odd
        for (int i = 0; i < n/4; ++i) {
            if (i % 2 == 0) {
                if (i != 0) {
                    cout << i << 1 << " " << i << 9 << " ";
                } else {
                    cout <<  1 << " " << 9 << " ";
                }
            } else {
                if (i != 1) {
                    cout << (i-1)/2 << 3 << " " << (i-1)/2 << 7 << " ";
                } else {
                    cout << 3 << " " << 7 << " ";
                }
            }
        }
        cout << endl;
    }


    return 0;
}
