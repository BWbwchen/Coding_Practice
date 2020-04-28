#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // brute force all node and its max high

    int li, hi, ri;
    int left = 1000000, right = 0;
    vector<int > high(10000+1, 0);

    while (cin >> li >> hi >> ri) {
        left = min(left, li);
        right = max(right, ri);
        for (int i = li; i < ri; ++i) {
            high[i] = max(high[i], hi);
        }
    }
    int pre = -1;
    for (int i = left; i <= right; ++i) {
        if (high[i] != pre) {
            cout << i << " " << high[i] << " " ;
            pre = high[i];
        }
    }


    return 0;
}
