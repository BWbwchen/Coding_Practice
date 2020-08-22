#define DEBUG
#include <bits/stdc++.h>
#define ll unsigned long long int
#define MAXN 10e16 + 1

using namespace std;


class problem {
    private :
        // pair {to_id, edge_id}
        vector<vector<pair<int, int>> > graph;
        vector<bool > visited;
        vector<ll > cnt;
        set<pair<ll, int> > st;
        vector<ll > w;
        int n;
        ll s;
        ll answer;

        void dfs (int start, int upEdge = -1) {
            // calculate the leaf node of this edge
            // if leaf => cnt = 1
            // for each neighbor
            //      dfs
            //      cnt[me] += cnt[neighbor]

            if (visited[start]) return ;
            bool isLeaf = true;
            visited[start] = true;
            
            for (auto [to, i] : graph[start]) {
                if (!visited[to]) {
                    isLeaf = false;
                    dfs(to, i) ;
                    if (upEdge != -1) cnt[upEdge] += cnt[i];
                }
            }
            if (isLeaf) cnt[upEdge] = 1;
        }
        void init () {
            graph.resize(n);
            visited.resize(n, false);
            cnt.resize(n, 0);
            w.resize(n, 0);
        }
        ll diff (int id) {
            return cnt[id] * w[id] - cnt[id] * (w[id]/2);
        }
        ll get_sum () {
            ll _s = 0;
            for (int i = 0; i < n-1; ++i) {
                // prevent sort every loop
                st.insert({diff(i), i});
                _s += cnt[i] * w[i];
            }
            return _s;
        }
    public :
        problem () {
            n = 0;
            s = 0;
            answer = 0;
            graph.clear();
            visited.clear();
            cnt.clear();
            st.clear();
            w.clear();
        }
        void input () {
            cin >> n >> s;
            init();

            int u, v;
            ll weight;
            for (int i = 0; i < n-1; ++i) {
                cin >> u >> v >> weight;
                u--; v--;
                while (weight > s) {
                    weight /= 2;
                    ++answer;
                }

                graph[u].push_back({v, i});
                graph[v].push_back({u, i});
                w[i] = weight;
            }
        }
        void solve () {
            dfs(0);
            ll sum = get_sum();

            while (sum > s) {
                auto id = st.rbegin()->second;
                sum -= diff(id);
                w[id] /= 2;
                st.erase(prev(st.end()));
                st.insert({diff(id), id});
                ++answer;
            }
            cout << answer << endl;
        }
};


int main () {
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int n_case;
    cin >> n_case;
    while (n_case--) {
        problem t;
        t.input();
        t.solve();
    }
    return 0;
}
