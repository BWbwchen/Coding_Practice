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
        unsigned long long n, k;
        cin >> n >> k;
        /*
        if (k%n == 0)
            cout << (n)*(k/(n-1)) - 1 << endl;
        else 
        */
        cout << n*(k/(n-1)) + ((k%(n-1) == 0) ? -1 : k%(n-1)) << endl;
    }



    return 0;
}
