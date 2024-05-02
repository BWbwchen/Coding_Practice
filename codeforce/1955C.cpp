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
using ll = long long int;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n, 0);
        for (auto &vv : v)
            cin >> vv;

        ll ans = 0;
        ll left = 0, right = v.size() - 1;
        while (left < right && k > 0) {
            ll to_remove = min(v[left], v[right]);
            ll victim = to_remove == v[left] ? left : right;
            bool both = v[left] == v[right];
            if (k - 2 * to_remove >= 0) {
                if (both) {
                    left++;
                    right--;
                    ans += 2;
                } else if (victim == left) {
                    v[right] -= to_remove;
                    left++;
                    ans++;
                } else {
                    v[left] -= to_remove;
                    right--;
                    ans++;
                }
                k -= 2 * to_remove;
            } else {
                // k < 2 * to_remove
                if (k + 1 == 2 * to_remove && victim == left)
                    ans++;
                break;
            }
        }
        bool only_one = left == right;
        if (only_one && k >= v[left]) {
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
