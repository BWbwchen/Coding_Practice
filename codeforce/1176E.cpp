#define DEBUG
#include <bits/stdc++.h>
#define ll long long int
#define INF 200000000

using namespace std;

int vertex, edge;
vector<vector<int>> adj;
vector<int> ret;

void bfs(int index) {
    ret = vector<int>(vertex+1, INF);

    queue<int> q;
    q.push(index);

    // start bfs
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        for (auto to : adj[top]) {
            if (ret[to] == INF) {
                ret[to] = ret[top] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    int t, v1, v2;
    cin >> t;
    while (t--) {
        cin >> vertex >> edge;
        adj = vector<vector<int >>(vertex+1);
        for (int i = 0; i < edge; ++i) {
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        bfs(1);

        vector<int> one, two;
        for (int i = 1; i <= vertex; ++i) {
            if (ret[i] & 1) one.push_back(i);
            else two.push_back(i);
        }

        // output
        if (one.size() < two.size()) {
            cout << one.size() << endl;
            for (auto v : one) cout << v << " ";
            cout << endl;
        } else {
            cout << two.size() << endl;
            for (auto v : two) cout << v << " ";
            cout << endl;
        }
    }
    return 0;
}
