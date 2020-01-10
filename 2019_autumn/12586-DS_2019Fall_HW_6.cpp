#define DEBUG
#define MAXN 1e7
#include <bits/stdc++.h>

using namespace std;

class solution {
   private:
    int _total;
    vector<vector<double>> _map;
    // 0 : left i
    // 1 : right j
    vector<int> ans;
    // 0 : e()
    // 1 : x :i -> x
    vector<double> e;
    vector<vector<double>> _floyd_record;

    bool float_equal(double a, double b) {
        if (fabs(a - b) < 0.0001)
            return true;
        else
            return false;
    }

    vector<vector<double>> _floyd() {
        vector<vector<double>> dist = _map;
        for (int middle = 0; middle < _total; ++middle) {
            for (int start = 0; start < _total; ++start) {
                for (int end = 0; end < _total; ++end) {
                    if (dist[start][middle] + dist[middle][end] <
                        dist[start][end]) {
                        dist[start][end] =
                            dist[start][middle] + dist[middle][end];
                    }
                }
            }
        }
        return dist;
    }
    vector<int> _sort_and_store(vector<double> target) {
        vector<pair<double, int>> to_sort;
        for (int i = 0; i < target.size(); ++i) {
            to_sort.push_back({target[i], i});
        }
        sort(to_sort.begin(), to_sort.end());
        reverse(to_sort.begin(), to_sort.end());
        vector<int> to_return;
        for (int i = 0; i < target.size(); ++i) {
            to_return.push_back(to_sort[i].second);
        }
        return to_return;
    }
    bool connected() {
        // bfs
        vector<bool> done;
        done.resize(_map.size(), false);

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (!done[top]) {
                done[top] = true;
                for (int i = 0; i < _map.size(); ++i) {
                    if (!float_equal(_map[top][i], MAXN) && done[i] == false) {
                        q.push(i);
                    }
                }
            }
        }
        for (int i = 0; i < done.size(); ++i) {
            if (!done[i]) return false;
        }
        return true;
    }
    void _ac() {
        // get shortest path
        vector<vector<double>> dist = _floyd();
        _floyd_record = dist;

        // sort path by distance
        vector<vector<int>> record_est;
        record_est.resize(_total, vector<int>(_total, 0));
        for (int from = 0; from < _total; ++from) {
            record_est[from] = _sort_and_store(dist[from]);
        }

        // find center
        e[0] = MAXN;
        e[1] = 0;
        ans[0] = ans[1] = -1;
        for (int i = 0; i < _total; ++i) {
            for (int j = i; j < _total; ++j) {
                for (int big = 0, small = 1; small < _total; ++small) {
                    // IMPORTANT need to think i == j (so need <=)
                    if (dist[j][record_est[i][big]] <=
                        dist[j][record_est[i][small]]) {
                        double temp = dist[j][record_est[i][big]] +
                                      dist[i][record_est[i][small]] +
                                      dist[i][j];
                        temp = temp / 2;
                        // initial
                        if (ans[0] == -1) {
                            e[0] = temp;
                            ans[0] = i;
                            ans[1] = j;
                            e[1] = dist[i][record_est[i][small]];
                        } else if (temp < e[0]) {
                            e[0] = temp;
                            ans[0] = i;
                            ans[1] = j;
                            e[1] = dist[i][record_est[i][small]];
                        } else if (float_equal(temp, e[0])) {
                            // vertex
                            if (i == j && ans[0] == ans[1] && i <= ans[0]) {
                                e[0] = temp;
                                ans[0] = i;
                                ans[1] = j;
                                e[1] = dist[i][record_est[i][small]];
                            } else if (i == j && ans[0] != ans[1]) {
                                e[0] = temp;
                                ans[0] = i;
                                ans[1] = j;
                                e[1] = dist[i][record_est[i][small]];
                            } else if (i < ans[0]) {
                                e[0] = temp;
                                ans[0] = i;
                                ans[1] = j;
                                e[1] = dist[i][record_est[i][small]];
                            } else if (i == ans[0]) {
                                if (j <= ans[1]) {
                                    e[0] = temp;
                                    ans[0] = i;
                                    ans[1] = j;
                                    e[1] = dist[i][record_est[i][small]];
                                }
                            }
                        }
                        big = small;
                    }
                }
            }
        }
    }

   public:
    solution(int x) {
        _total = x;
        _map.resize(_total, vector<double>(_total, MAXN));
        for (int i = 0; i < _total; ++i) _map[i][i] = 0;
        for (int i = 0; i < 2; ++i) ans.push_back(-1);
        _floyd_record.resize(_total, vector<double>(_total, MAXN));
        e = {0, 0};
    }
    void add(int v1, int v2, double weight) {
        if (v1 == v2 || v1 >= _total || v2 >= _total) return;
        _map[v1][v2] = weight;
        _map[v2][v1] = weight;
    }
    void remove(int v1, int v2) {
        if (v1 == v2 || v1 >= _total || v2 >= _total) return;
        _map[v1][v2] = MAXN;
        _map[v2][v1] = MAXN;
    }
    vector<int> ac() {
        if (!connected()) {
            ans[0] = -1;
            return ans;
        }
        _ac();
        return ans;
    }
    double sospd() {
        if (!connected()) return -1;
        _ac();
        // add new node
        for (int i = 0; i < _total; ++i) {
            _map[i].push_back(MAXN);
        }
        _map.push_back(vector<double>(_total + 1, MAXN));
        // write the information
        _map[_total][_total] = 0;
        _map[_total][ans[0]] = e[0] - e[1];
        _map[_total][ans[1]] = _map[ans[0]][ans[1]] - _map[_total][ans[0]];
        _map[ans[0]][_total] = _map[_total][ans[0]];
        _map[ans[1]][_total] = _map[_total][ans[1]];

        // dijkstra
        // initial
        vector<double> key_value(_total + 1, MAXN);
        bool visited[_total + 1] = {false};

        key_value[_total] = 0;
        visited[_total] = true;
        for (int i = 0; i < _total + 1; ++i) {
            if (!float_equal(_map[_total][i], MAXN)) {
                key_value[i] = _map[_total][i];
            }
        }

        for (int i = 0; i < _total + 1; ++i) {
            // find the min key value node
            double min = MAXN;
            int min_id = _total;

            for (int j = 0; j < _total + 1; ++j) {
                // TODO : maybe float_equal
                if (!visited[j] && key_value[j] < min) {
                    min = key_value[j];
                    min_id = j;
                }
            }

            visited[min_id] = true;
            // update the value adj the min_id
            for (int j = 0; j < _total + 1; ++j) {
                if (!float_equal(_map[min_id][j], MAXN)) {
                    // TODO : maybe float_equal
                    if (!visited[j] && min + _map[min_id][j] < key_value[j]) {
                        key_value[j] = min + _map[min_id][j];
                    }
                }
            }
        }
        // remove map
        for (int i = 0; i < _total; ++i) {
            _map[i].pop_back();
        }
        _map.pop_back();
        // for (int i = 0; i < _total + 1; ++i) cout << key_value[i] << " ";
        // cout << endl;
        double _sum = 0;
        for (int i = 0; i < _total + 1; ++i) _sum += key_value[i];
        return _sum;
    }
    double diameter() {
        if (!connected()) return -1;
        _ac();
        return 2 * e[0];
    }
};

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif

    int n;
    cin >> n;
    solution t(n);
    string op;
    while (cin >> op) {
        if (op == "Add") {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            t.add(v1, v2, w);
        } else if (op == "AC") {
            if (n == 1) {
                cout << 0 << endl;
                continue;
            }
            auto a = t.ac();
            if (a[0] < 0)
                cout << "Not connected graph" << endl;
            else if (a[0] == a[1])
                cout << a[0] << endl;
            else
                cout << a[0] << " " << a[1] << endl;
        } else if (op == "Diameter") {
            if (n == 1) {
                cout << 0 << endl;
                continue;
            }
            auto a = t.diameter();
            if (a < 0)
                cout << "Not connected graph" << endl;
            else
                cout << int(a) << endl;
        } else if (op == "SOSPD") {
            if (n == 1) {
                cout << 0 << endl;
                continue;
            }
            auto a = t.sospd();
            if (a < 0)
                cout << "Not connected graph" << endl;
            else {
                if ((int)(10 * a) % 10 != 0) {
                    printf("%.1f\n", a);
                } else
                    cout << int(a) << endl;
            }
        } else if (op == "Delete") {
            int v1, v2;
            cin >> v1 >> v2;
            t.remove(v1, v2);
        } else {
            // fuck you
        }
    }

    return 0;
}
