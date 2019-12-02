#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>
#define OK 1
#define NO 0
#define PRIM 1
#define KRUSAL 2
#define DIJKSTRA 3
#define BELLMAN 4
#define FLOYD 5
#define SOLLIN 6

using namespace std;

class edge {
   public:
    int weight;
    double _rate;
    int start;  // start
    int end;    // end

    edge(int w, int s, int e) {
        weight = w;
        _rate = -MAXN;
        start = s;
        end = e;
    }
    edge(double r, int s, int e) {
        weight = MAXN;
        _rate = r;
        start = s;
        end = e;
    }
    edge() {
        weight = MAXN;
        _rate = -MAXN;
        start = -1;
        end = -1;
    }
    bool operator<(const edge& rhs) { return this->weight < rhs.weight; }
};

class Graph {
   private:
    // adjlist[start][end] :=  edge start --> end
    vector<vector<edge>> adjlist;
    vector<vector<edge>> adjlist_rate;
    vector<edge> all_edge;
    int vertex;

    void _dfs(int start, int gone[]) {
        gone[start] = 1;
        for (int i = 0; i < adjlist[start].size(); ++i) {
            if (!gone[adjlist[start][i].end]) {
                _dfs(adjlist[start][i].end, gone);
            }
        }
    }

   public:
    Graph(int total) {
        vertex = total;

        // adjlist
        for (int i = 0; i < vertex; ++i) {
            vector<edge> a = {};
            adjlist.push_back(a);
        }
        // adjlist rate
        for (int i = 0; i < vertex; ++i) {
            vector<edge> a = {};
            adjlist_rate.push_back(a);
        }
    }
    void add(int v1, int v2, int cost, double rate = -100, int mode = NO) {
        adjlist[v1].push_back(edge(cost, v1, v2));
        adjlist[v2].push_back(edge(cost, v2, v1));

        if (mode == OK) {
            adjlist_rate[v1].push_back(edge(rate, v1, v2));
            adjlist_rate[v2].push_back(edge(rate, v2, v1));
        }

        all_edge.push_back(edge(cost, v1, v2));
    }
    void remove(int v1, int v2, int mode = NO) {
        for (int i = 0; i < adjlist[v1].size(); ++i) {
            if (adjlist[v1][i].end == v2) {
                adjlist[v1].erase(adjlist[v1].begin() + i);
                break;
            }
        }
        for (int i = 0; i < adjlist[v2].size(); ++i) {
            if (adjlist[v2][i].end == v1) {
                adjlist[v2].erase(adjlist[v2].begin() + i);
                break;
            }
        }
        // rate
        if (mode == NO) return;
        for (int i = 0; i < adjlist_rate[v1].size(); ++i) {
            if (adjlist_rate[v1][i].end == v2) {
                adjlist_rate[v1].erase(adjlist_rate[v1].begin() + i);
                break;
            }
        }
        for (int i = 0; i < adjlist_rate[v2].size(); ++i) {
            if (adjlist_rate[v2][i].end == v1) {
                adjlist_rate[v2].erase(adjlist_rate[v2].begin() + i);
                break;
            }
        }
    }
    bool dfs() {
        int gone[vertex] = {0};
        _dfs(0, gone);

        // check for no visited => connected component
        for (int i = 0; i < vertex; ++i)
            if (!gone[i]) return false;
        return true;
    }

    void prim() {
        // check whether is conneted component
        if (!dfs()) {
            cout << "Error\n";
            return;
        }

        // initial
        int gone[vertex] = {0};
        auto cmp = [](edge a, edge b) { return a.weight > b.weight; };
        priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
        vector<int> predecessor(vertex, -1);

        // push the edge adjoint the start node
        gone[0] = 1;
        for (int i = 0; i < adjlist[0].size(); ++i) pq.push(adjlist[0][i]);

        int last_man = -1;
        long long int ans = 0LL;
        // prim
        for (int i = 0; i < vertex - 1; ++i) {
            // find the min key node to deal
            auto min = pq.top();
            pq.pop();

            gone[min.end] = 1;
            predecessor[min.end] = min.start;
            last_man = min.end;
            // accumulate edge cost
            ans += min.weight;
            // push all the edge of min.end
            for (int i = 0; i < adjlist[min.end].size(); ++i)
                if (!gone[adjlist[min.end][i].end])
                    pq.push(adjlist[min.end][i]);
        }
        cout << ans << endl;
    }

    void important() {
        for (int i = 0; i < all_edge.size(); ++i) {
            auto record = all_edge[i];
            // remove edge from adjlist
            remove(record.start, record.end, NO);
            if (!dfs()) {
                cout << "Yes\n";
                add(record.start, record.end, record.weight);
                return;
            }
            // add edge
            add(record.start, record.end, record.weight, NO);
        }
        cout << "No\n";
    }
    void dijkstra(int from, int dest) {
        // check whether is conneted component
        if (!dfs()) {
            cout << "Error\n";
            return;
        }
        // initial
        bool visited[vertex] = {0};
        // first = key_value, second = index
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> key_value(vertex, MAXN);

        key_value[from] = 0;
        for (int i = 0; i < key_value.size(); ++i) pq.push({key_value[i], i});

        visited[from] = 1;

        for (int i = 0; i < vertex - 1; ++i) {
            auto min = pq.top();
            pq.pop();

            visited[min.second] = 1;
            // update near node key_value
            for (int j = 0; j < adjlist[min.second].size(); ++j) {
                if (min.first + adjlist[min.second][j].weight <
                    key_value[adjlist[min.second][j].end]) {
                    key_value[adjlist[min.second][j].end] =
                        min.first + adjlist[min.second][j].weight;
                    pq.push({key_value[adjlist[min.second][j].end],
                             adjlist[min.second][j].end});
                }
            }
        }
        cout << key_value[dest] << endl;
    }

    void accumulate(double& ans, vector<pair<int, double>> predecessor,
                    int target) {
        if (predecessor[target].first == -1) return;
        ans *= predecessor[target].second;
    }

    void exchange(int from, int dest, int num, int mode, int limit = -1) {
        // bellman
        vector<double> key_value(vertex, -MAXN);
        // predecessor, from here to its predecessor 's rate
        vector<pair<int, double>> predecessor(vertex, make_pair(-1, -MAXN));
        key_value[from] = 1;

        for (int i = 0; i < vertex - 1; ++i) {
            // for every node
            for (int j = 0; j < vertex; ++j) {
                // it's near node
                for (int near = 0; near < adjlist_rate[j].size(); ++near) {
                    // update the key_value
                    auto near_node = adjlist_rate[j][near];
                    if (key_value[near_node.start] * near_node._rate >
                        key_value[near_node.end]) {
                        key_value[near_node.end] =
                            key_value[near_node.start] * near_node._rate;
                        predecessor[near_node.end] = make_pair(
                            near_node.start, key_value[near_node.end]);
                    }
                }
            }
        }
        // from predecessor make the path
        double ans = 1;
        accumulate(ans, predecessor, dest);
        cout << (int)(num*ans) << endl;
    }
};

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif

    int total;
    cin >> total;
    Graph t(total);
    string cmd;

    while (cin >> cmd) {
        if (cmd == "Add") {
            int v1, v2, cost;
            double rate;
            cin >> v1 >> v2 >> cost >> rate;
            t.add(v1, v2, cost, rate, OK);
        } else if (cmd == "Delete") {
            int v1, v2;
            cin >> v1 >> v2;
            t.remove(v1, v2, OK);
        } else if (cmd == "Map") {
            t.prim();
        } else if (cmd == "ImportantBus") {
            t.important();
        } else if (cmd == "Shortest") {
            int start, end;
            cin >> start >> end;
            t.dijkstra(start, end);
        } else if (cmd == "CreditExchange") {
            int start, end, num;
            cin >> start >> end >> num;
            t.exchange(start, end, num, 1);
        } else if (cmd == "CreditExchange2") {
            int start, end, num, limit;
            cin >> start >> end >> num >> limit;
            t.exchange(start, end, num, 2, limit);
        } else {
            // do nothing
        }
    }

    return 0;
}

