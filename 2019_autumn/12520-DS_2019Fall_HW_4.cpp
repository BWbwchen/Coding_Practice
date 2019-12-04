#define DEBUG
#define LLMAXN 9223372036854775800
#define MAXN 1e9
#include <bits/stdc++.h>
#define OK 1
#define NO 0

using namespace std;

class edge {
   public:
    int weight;
    double _rate;
    int start;  // start
    int end;    // end
    bool valid;

    edge(int w, int s, int e) {
        weight = w;
        _rate = -MAXN;
        start = s;
        end = e;
        valid = true;
    }
    edge(double r, int s, int e) {
        weight = MAXN;
        _rate = r;
        start = s;
        end = e;
        valid = true;
    }
    edge() {
        weight = MAXN;
        _rate = -MAXN;
        start = -1;
        end = -1;
        valid = true;
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
            if (adjlist[start][i].valid && !gone[adjlist[start][i].end]) {
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
    void add(int v1, int v2, int cost, double rate) {
        if (v1 == v2) return;
        if (v1 >= vertex || v2 >= vertex) return;
        adjlist[v1].push_back(edge(cost, v1, v2));
        adjlist[v2].push_back(edge(cost, v2, v1));

        adjlist_rate[v1].push_back(edge(rate, v1, v2));
        adjlist_rate[v2].push_back(edge(rate, v2, v1));

        all_edge.push_back(edge(cost, v1, v2));
    }
    void remove(int v1, int v2) {
        if (v1 == v2) return;
        if (v1 >= vertex || v2 >= vertex) return;
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
        if (vertex == 0) return true;
        int gone[vertex] = {0};
        _dfs(0, gone);

        // check for no visited => connected component
        for (int i = 0; i < vertex; ++i)
            if (!gone[i]) return false;
        return true;
    }

    void prim() {
        if (vertex == 0) {
            cout << "Error\n";
            return;
        }
        // check whether is conneted component
        if (!dfs()) {
            cout << "Error\n";
            return;
        }

        // initial
        bool gone[vertex] = {false};
        auto cmp = [](edge a, edge b) { return a.weight > b.weight; };
        priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
        vector<int> predecessor(vertex, -1);

        // push the edge adjoint the start node
        gone[0] = 1;
        for (int i = 0; i < adjlist[0].size(); ++i) pq.push(adjlist[0][i]);

        long long int ans = 0LL;
        int total_num = 1;
        // prim
        while (total_num != vertex) {
            // find the min key node to deal
            auto min = pq.top();
            pq.pop();

            if (gone[min.end]) continue;
            gone[min.end] = true;
            predecessor[min.end] = min.start;
            total_num++;
            // accumulate edge cost
            ans += min.weight;
            // push all the edge of min.end
            for (int j = 0; j < adjlist[min.end].size(); ++j)
                if (!gone[adjlist[min.end][j].end])
                    pq.push(adjlist[min.end][j]);
        }
        cout << ans << endl;
    }

    void important() {
        vector<edge> temp = all_edge;
        for (int i = 0; i < temp.size(); ++i) {
            auto record = temp[i];
            // remove edge from adjlist
            for (int j = 0; j < adjlist[record.start].size(); ++j) {
                if (adjlist[record.start][j].end == record.end) {
                    adjlist[record.start][j].valid = false;
                    break;
                }
            }
            for (int j = 0; j < adjlist[record.end].size(); ++j) {
                if (adjlist[record.end][j].end == record.start) {
                    adjlist[record.end][j].valid = false;
                    break;
                }
            }
            if (!dfs()) {
                cout << "Yes\n";
                for (int j = 0; j < adjlist[record.start].size(); ++j) {
                    if (adjlist[record.start][j].end == record.end) {
                        adjlist[record.start][j].valid = true;
                        break;
                    }
                }
                for (int j = 0; j < adjlist[record.end].size(); ++j) {
                    if (adjlist[record.end][j].end == record.start) {
                        adjlist[record.end][j].valid = true;
                        break;
                    }
                }
                return;
            }
            // add edge
            for (int j = 0; j < adjlist[record.start].size(); ++j) {
                if (adjlist[record.start][j].end == record.end) {
                    adjlist[record.start][j].valid = true;
                    break;
                }
            }
            for (int j = 0; j < adjlist[record.end].size(); ++j) {
                if (adjlist[record.end][j].end == record.start) {
                    adjlist[record.end][j].valid = true;
                    break;
                }
            }
        }
        cout << "No\n";
    }
    void dijkstra(int from, int dest) {
        if (vertex == 0 || from == dest || dest >= vertex || from >= vertex) {
            cout << 0 << endl;
            return;
        }
        // initial
        vector<long long int> key_value(vertex, LLMAXN);
        bool visited[vertex] = {false};

        key_value[from] = 0;
        visited[from] = true;
        for (int i = 0; i < adjlist[from].size(); ++i)
            key_value[adjlist[from][i].end] = adjlist[from][i].weight;

        for (int i = 0; i < vertex - 1; ++i) {
            // find the min key value node
            long long int min = LLMAXN;
            int min_id = from;

            for (int j = 0; j < vertex; ++j) {
                if (!visited[j] && key_value[j] < min) {
                    min = key_value[j];
                    min_id = j;
                }
            }

            visited[min_id] = true;
            // update the value adj the min_id
            for (int j = 0; j < adjlist[min_id].size(); ++j) {
                if (!visited[adjlist[min_id][j].end] &&
                    min + adjlist[min_id][j].weight <
                        key_value[adjlist[min_id][j].end]) {
                    key_value[adjlist[min_id][j].end] =
                        min + adjlist[min_id][j].weight;
                }
            }
        }
        if (key_value[dest] == LLMAXN)
            cout << "Error" << endl;
        else
            cout << key_value[dest] << endl;
    }

    void exchange(int from, int dest, long long int num) {
        if (vertex == 0 || from == dest || from >= vertex || dest >= vertex) {
            cout << num << endl;
            return;
        }
        // dijkstra
        // initial
        vector<long long int> key_value(vertex, -MAXN);
        bool visited[vertex] = {false};

        key_value[from] = num;
        visited[from] = true;
        for (int i = 0; i < adjlist_rate[from].size(); ++i)
            key_value[adjlist_rate[from][i].end] =
                num * adjlist_rate[from][i]._rate;

        for (int i = 0; i < vertex - 1; ++i) {
            // find the min key value node
            double max_rate = 0;
            int max_id = from;

            for (int j = 0; j < vertex; ++j) {
                if (!visited[j] && (key_value[j] > max_rate)) {
                    max_rate = key_value[j];
                    max_id = j;
                }
            }

            visited[max_id] = true;
            // update the value adj the max_id
            for (auto near_edge : adjlist_rate[max_id]) {
                if (!visited[near_edge.end] &&
                    key_value[near_edge.start] * near_edge._rate >
                        key_value[near_edge.end]) {
                    key_value[near_edge.end] =
                        key_value[near_edge.start] * near_edge._rate;
                }
            }
        }
        cout << key_value[dest] << endl;
    }
    void dfs_rate(long long int& ans, int from, int dest, long long int num,
                  long long int limit, bool visited[], vector<double> path) {
        // mark visited
        // if from == dest , calculate ans
        // else :
        // for every near edge
        // if !visited
        //      dfs()
        //
        // remove visited
        visited[from] = true;
        // calculate
        long long int temp = num;
        if (from == dest) {
            if (path.size() > limit) {
                visited[from] = false;
                return;
            }
            vector<double>::iterator it;
            // cout << "travel path\n";
            for (it = path.begin(); it != path.end(); ++it) {
                // cout << (*it) << " ";
                temp *= (*it);
            }
            // cout << endl;
            if (temp > ans) ans = temp;
            visited[from] = false;
            return;
        }

        for (auto road : adjlist_rate[from]) {
            if (!visited[road.end]) {
                path.push_back(road._rate);
                dfs_rate(ans, road.end, dest, num, limit, visited, path);
                path.pop_back();
            }
        }
        visited[from] = false;
    }

    void loop_path(int from, int dest, long long int num, long long int limit,
                   bool visited[], vector<double> path,
                   vector<vector<double>>& to_ans, bool flag) {
        // mark visited
        // if from == dest , calculate ans
        // else :
        // for every near edge
        // if !visited
        //      dfs()
        //
        // remove visited
        if (flag) visited[from] = true;
        // calculate
        long long int temp = num;
        if (from == dest && path.size() != 0) {
            to_ans.push_back(path);
            visited[from] = false;
            return;
        }

        for (auto road : adjlist_rate[from]) {
            if (!visited[road.end]) {
                path.push_back(road._rate);
                loop_path(road.end, dest, num, limit, visited, path, to_ans,
                          true);
                path.pop_back();
            }
        }
        visited[from] = false;
    }

    void exchange_two(int from, int dest, long long int num,
                      long long int limit) {
        // dfs ?
        if (vertex == 0 || from >= vertex || dest >= vertex || limit == 0) {
            cout << num << endl;
            return;
        }

        long long int ans = -LLMAXN;
        bool visited[vertex] = {false};
        vector<double> path;

        // what if loop ??
        if (from == dest) {
            vector<vector<double>> to_ans;
            loop_path(from, dest, num, limit, visited, path, to_ans, false);
            bool is_ok = false;
            for (auto pre_ans : to_ans) {
                if (pre_ans.size() > limit) continue;

                is_ok = true;
                // calculate answer
                long long int temp = num;
                vector<double>::iterator it;
                // cout << "travel path\n";
                for (it = pre_ans.begin(); it != pre_ans.end(); ++it) {
                    // cout << (*it) << " ";
                    temp *= (*it);
                }
                // cout << endl;
                if (temp > ans) ans = temp;
            }

            if (!is_ok)
                cout << num << endl;
            else
                cout << ans << endl;
            return;
        }

        dfs_rate(ans, from, dest, num, limit, visited, path);
        if (ans == -LLMAXN)
            cout << 0 << endl;
        else
            cout << ans << endl;
        // cout << "---------------------------------\n";
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
            t.add(v1, v2, cost, rate);
        } else if (cmd == "Delete") {
            int v1, v2;
            cin >> v1 >> v2;
            t.remove(v1, v2);
        } else if (cmd == "Map") {
            t.prim();
        } else if (cmd == "ImportantBus") {
            t.important();
        } else if (cmd == "Shortest") {
            int start, end;
            cin >> start >> end;
            t.dijkstra(start, end);
        } else if (cmd == "CreditExchange") {
            int start, end;
            long long int num;
            cin >> start >> end >> num;
            t.exchange(start, end, num);
        } else if (cmd == "CreditExchange2") {
            int start, end;
            long long int num, limit;
            cin >> start >> end >> num >> limit;
            t.exchange_two(start, end, num, limit);
        } else {
            // do nothing
        }
    }

    return 0;
}

