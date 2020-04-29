#define DEBUG
#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, b;
    vector<int > a(MAXN);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        a[i] = b;
    }
    sort(a.begin(), a.begin()+n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
