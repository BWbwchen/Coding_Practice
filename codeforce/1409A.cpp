#define DEBUG
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
    int a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        int step = ceil((int)abs(b-a) / 10);
        if ((int)abs(b-a) % 10 != 0) step ++;
        cout << step << endl;
    }

    return 0;
}
