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
        vector<int > cost;
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
            cnt.resize(n-1, 0);
            w.resize(n-1, 0);
            cost.resize(n-1, 0);
        }
        ll diff (int id) {
            return cnt[id] * w[id] - cnt[id] * (w[id]/2);
        }
        vector<ll > make_dp (int _c) {
            ll _s = 0;
            for (int i = 0; i < n-1; ++i) {
                // prevent sort every loop
                if (cost[i] == _c) {
                    st.insert({diff(i), i});
                    _s += cnt[i] * w[i];
                }
            }

            vector<ll > res;
            res.push_back(_s);
            while (_s > 0 && !st.empty()) {
                auto id = st.rbegin()->second;
                _s -= diff(id);
                w[id] /= 2;
                res.push_back(_s);
                st.erase(prev(st.end()));
                st.insert({diff(id), id});
            }
            return res;
        }
    public :
        problem () {
            n = 0;
            s = 0;
            answer = MAXN;
            graph.clear();
            visited.clear();
            cnt.clear();
            st.clear();
            w.clear();
            cost.clear();
        }
        void input () {
            cin >> n >> s;
            init();

            int u, v;
            for (int i = 0; i < n-1; ++i) {
                cin >> u >> v >> w[i] >> cost[i];
                u--; v--;
                /*
                while (weight > s) {
                    weight /= 2;
                    ++answer;
                }
                */

                graph[u].push_back({v, i});
                graph[v].push_back({u, i});
            }
        }
        void solve () {
            dfs(0);

            vector<ll > v1 = make_dp(1);
            vector<ll > v2 = make_dp(2);


            ll right = v2.size()-1;
            // make left, right pair in O(n) 
            // if use double for loop O(n^2) will get TLE
            for (ll left = 0; left < v1.size(); ++left) {
                while (right > 0 && v1[left] + v2[right-1] <= s) --right;
                if (v1[left] + v2[right] <= s) {
                    answer = min(answer, left+2*right);
                }
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
