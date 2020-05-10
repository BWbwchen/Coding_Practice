#define DEBUG
#define MAXN 10000000
#include <bits/stdc++.h>
using namespace std;

void template_output(int limit, int bias ) {
    for (int i = 0; i < limit/6 - 1*bias; ++i) {
        int a = 6*i+1;
        cout << a << " ";
        cout << a+3 << " ";
        cout << a+1 << " ";
        cout << a+5 << " ";
        cout << a+2 << " ";
        cout << a+4 << " ";
    }
}
void solve (int n) {

    if (n%6 == 5) {
        template_output(n, 0);
        cout << n-4 << " ";
        cout << n-1 << " ";
        cout << n-3 << " ";
        cout << n-0 << " ";
        cout << n-2 << " ";
    } else if (n%6 == 4) {
        template_output(n, 0);
        cout << n-1 << " ";
        cout << n-3 << " ";
        cout << n-0 << " ";
        cout << n-2 << " ";
    } else if (n%6 == 3) {
        if (n == 3) {
            cout << -1 << endl;
            return;
        }
        template_output(n, 1);
        cout << n-8 << " ";
        cout << n-4 << " ";
        cout << n-0 << " ";
        cout << n-2 << " ";
        cout << n-6 << " ";
        cout << n-3 << " ";
        cout << n-1 << " ";
        cout << n-5 << " ";
        cout << n-7 << " ";
    } else if (n%6 == 2) {
        if (n == 2) {
            cout << -1 << endl;
            return;
        }
        template_output(n, 1);
        cout << n-6 << " ";
        cout << n-4 << " ";
        cout << n-2 << " ";
        cout << n-0 << " ";
        cout << n-3 << " ";
        cout << n-1 << " ";
        cout << n-5 << " ";
        cout << n-7 << " ";
    } else if (n%6 == 1) {
        template_output(n, 0);
        cout << n << " ";
    } else {
        template_output(n, 0);
    }
    cout << endl;
}


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
        solve(n);
    }

    return 0;
}
