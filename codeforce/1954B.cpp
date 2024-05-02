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
        int n;
        cin >> n;

        vector<int> v(n, 0);
        for (auto &vv : v)
            cin >> vv;

        // observation:
        // 1. what make an array beautiful?
        // --> they should have peak, and the base level with value x, which is
        // the final beautiful array's value.
        // --> e.g. ___y___k___
        // 2. what does an non-beautiful array look like?
        // --> it has something like
        // --> e.g. __yk____
        int ans = std::numeric_limits<int>::max();
        int base = 0;
        unordered_map<int, int> um;
        for (auto &vv : v)
            um[vv]++;

        int count = 0;
        for (auto &p : um) {
            if (p.second > count) {
                count = p.second;
                base = p.first;
            }
        }

        // Now we know the base value. Find all the peak.
        vector<int> peak;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != base)
                peak.push_back(i);
        }

        if (peak.size() >= 1)
            ans = min(ans, peak[0]);
        for (int i = 1; i < peak.size(); ++i) {
            ans = min(ans, peak[i] - peak[i - 1] - 1);
        }
        if (peak.size() >= 1)
            ans = min(ans, (int) v.size() - peak[peak.size() - 1] - 1);

        cout << (ans == std::numeric_limits<int>::max() ? -1 : ans) << endl;
    }

    return 0;
}
