#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int > v;
    priority_queue<pair<int, int>> pq;
    while (cin >> n) {
        int a, b;
        while (n--) {
            cin >> a >> b;
            //pq.push(make_pair(a, b));
            pq.push(make_pair(b, a));
        }
        int ans = 0;
        int stupid = 0; // the total print time
        pair <int , int > big, pre;
        while (!pq.empty()) {
            pre = big;
            big = pq.top();
            pq.pop();
            stupid += big.second;
            ans = max(ans, stupid+big.first);
        }
        cout << ans << endl;
    }


    return 0;
}
