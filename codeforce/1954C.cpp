#define MAXN 2000000000
#define llu unsigned long long
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
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
        string x, y;
        cin >> x >> y;

        int n = x.size();

        // once you have a larger LSB, the other bit should be the smallest!

        // suppose that I want x is larger than y.
        bool same = false;
        for (int i = 0; i < n; ++i) {
            // 4 cases:
            // 1., 2. same in history(same == false)
            // if x > y -> do nothing
            // if x < y -> swap
            // 3., 4. in history not the same but x > y (same == true)
            // if x > y -> swap
            // if x < y -> do nothing
            if (same == (x[i] > y[i]))
                swap(x[i], y[i]);
            same |= (x[i] != y[i]);
        }
        cout << x << endl;
        cout << y << endl;
    }

    return 0;
}
