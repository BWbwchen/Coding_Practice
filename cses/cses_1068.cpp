//#define DEBUG
#define MAXN 2000000000
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n!=1) {
        cout << n << " ";
        if (n % 2 == 1) n = 3*n+1;
        else n /= 2;
    }
    cout << n << " ";


    return 0;
}
