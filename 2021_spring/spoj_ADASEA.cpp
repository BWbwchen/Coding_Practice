#define DEBUG
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll row, col;
vector<vector<bool>> m(1000, vector<bool>(1000, false));

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

ll dfs(ll r, ll c) {
    ll piece = 1;
    m[r][c] = false;

    // up
    if (r - 1 >= 0 && m[r-1][c]) {
        m[r-1][c] = false;
        piece += dfs(r-1, c);
    }

    // left
    if (c - 1 >= 0 && m[r][c - 1]) {
        m[r][c - 1] = false;
        piece += dfs(r, c - 1);
    }

    // right
    if (c + 1 < col && m[r][c + 1]) {
        m[r][c + 1] = false;
        piece += dfs(r, c + 1);
    }
    // down
    if (r + 1 < row && m[r+1][c]) {
        m[r+1][c] = false;
        piece += dfs(r+1, c);
    }

    return piece;
}

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ll t;
    cin >> t;
    while (t--) {
        cin >> row >> col;
        // input
        char c;
        for (ll i = 0; i < row; ++i) {
            for (ll j = 0; j < col; ++j) {
                cin >> c;
                if (c == '#') {
                    m[i][j] = true;
                } else {
                    m[i][j] = false;
                }
            }
        }

        ll ans = 0;
        
        // solve it !
        for (ll i = 0; i < row; ++i) {
            for (ll j = 0; j < col; ++j) {
                if (m[i][j] == true) {
                    // dfs !
                    ll temp = dfs(i, j);
                    ans += temp * temp;
                }
            }
        }

        // output 
        if (ans % (row * col) == 0) {
            printf("%lld\n", ans / (row * col));
        } else {
            ll g = gcd(ans, row*col);
            printf("%lld / %lld\n", ans / g, (row * col) / g);
        }
    }
    return 0;
}
