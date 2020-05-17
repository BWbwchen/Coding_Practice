#include <vector>
#define DEBUG
#define MAXN 10000000
#define ll long long int
#include <bits/stdc++.h>
using namespace std;


int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;


    // (n-1) 1
    //  n-1  s-n+1
    //  s-n
    //  what about s-n = n-1 ?
    //  s = 2n - 1
    //  n-1 >= s-n Not good
    //  n > s - n Not good
    if (n-1 >= s-n) {
        cout << "NO" << endl;
        return 0;
    }

    // n-1 1
    cout << "YES" << endl;
    for (int i = 1; i <= n-1; ++i) cout << 1 << " ";
    cout << s-n+1 << endl;
    cout << s-n << endl;

    return 0;
}
