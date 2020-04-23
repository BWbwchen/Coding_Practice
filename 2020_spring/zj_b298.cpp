// https://zerojudge.tw/ShowProblem?problemid=b298
#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> N(10005, vector<int>());

    int n, m, l, q;
    cin >> n >> m >> l >> q;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        N[a].push_back(b);
    }
    queue<int> problem;
    bitset<10005> bad;
    bad.reset();
    for (int i = 0; i < l; ++i) {
        int x;
        cin >> x;
        bad.set(x);
        problem.push(x);
    }
    // solve
    while (!problem.empty()) {
        // for all member of the top element
        int top_ele = problem.front();
        problem.pop();
        for (auto i : N[top_ele]) {
            if (bad[i] == 0) problem.push(i);
            bad.set(i);
        }
    }
    for (int i = 0; i < q; ++i) {
        int y;
        cin >> y;
        if (bad[y]) {
            cout << "TUIHUOOOOOO\n";
        } else {
            cout << "YA~~\n";
        }
    }

    return 0;
}
