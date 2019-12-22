#define DEBUG
#define MAXN 1010
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif

    int n, temp;
    cin >> n;

    vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) cin >> a[i];

    // from i , I will get how long strictly increase
    vector<int> now_after_long(n, 1);

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1])
            now_after_long[i] = now_after_long[i + 1] + 1;
        else
            now_after_long[i] = 1;
    }

    // for now i , I will get how long strictly increase
    vector<int> now_before_long(n, 1);
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] < a[i])
            now_before_long[i] = now_before_long[i - 1] + 1;
        else
            now_before_long[i] = 1;
    }

    int ans = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i + 1])
            ans = max(ans, now_after_long[i + 1] + now_before_long[i - 1]);
    }
    // what if i didn't take any?
    for (int i = 0; i < n; ++i) ans = max(ans, now_before_long[i]);

    cout << ans << endl;

    return 0;
}
