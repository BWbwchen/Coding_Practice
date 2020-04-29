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

    vector<int > v;
    int n;
    while (cin >> n) {
        v.push_back(n);
    }

    vector<int> dp(v.size(), 1);
    /*
     * O(n^2)
    for (int i = 1; i < v.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    */

    // increasing stack, but if a smaller num push in, CANNOT remove all number
    // greater than it, because those number maybe can be the answer of remain
    vector<int > inc_stack;
    inc_stack.push_back(v[0]);
    // j dont need to start from 0 to end
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] <= inc_stack.back()) {
            auto it = lower_bound(inc_stack.begin(), inc_stack.end(), v[i]);
            *it = v[i];
            dp[i] = max(dp[i], (int)(it - inc_stack.begin() + 1));
        } else {
            inc_stack.push_back(v[i]);
            dp[i] = max(dp[i], (int)inc_stack.size());
        }
    }
    
    // get max id, and length
    int max_id = 0, length = 0;
    for (int i = dp.size()-1; i >= 0; --i) {
        if (length < dp[i]) {
            max_id = i;
            length = dp[i];
        }
    }
    cout << length << endl << "-" << endl;

    vector<int > ans;
    ans.reserve(length);
    for (int i = max_id; length > 0; --i) {
        if (dp[i] == length) {
            ans.push_back(v[i]);
            length--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
