#define DEBUG
#define MAXN 0xffffffffffffffff
#define ULLINT unsigned long long int 
#include <bits/stdc++.h>
 
 
using namespace std;
 
 
void dijkstra (int start, int total_node, vector<vector<ULLINT >>& graph) {
    // pair for first is distance, second is index
    priority_queue<pair<ULLINT, int > , vector<pair<ULLINT ,int > >, greater<pair<ULLINT , int >>> q;
    vector<int > had;
    q.push({graph[start][start], start});
    had.push_back(start);
 
    while (!q.empty()) {
        auto node = q.top().second;
        q.pop();
        // adjecent node of 'node'
        for (int i = 1; i <= total_node; ++i) {
            // check adjacent 
            if (graph[node][i] == MAXN || graph[i][node] == MAXN ||
                graph[node][i] == 0 || graph[i][node] == 0 ) continue;
            // mark traveled 
            if (find(had.begin(), had.end(), i) == had.end()) {
                q.push({graph[node][i], i});
                had.push_back(i);
            }
            // relax 
            if (graph[start][i] > graph[start][node] + graph[node][i]) {
                graph[i][start] = graph[start][i] = graph[start][node] + graph[node][i];
            }
        }
    }
}
    
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif
 
    int vertices, edges, kth;
    cin >> vertices >> edges >> kth;
    vector <vector<ULLINT >> graph(vertices+1, vector<ULLINT > (vertices+1, MAXN));
    // weight , start , end 
    vector <pair<int , pair<int , int >>> pre;
 
    // initialize map
    for (int i = 0; i < edges; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        //graph[a][b] = graph[b][a] = c;
        pre.push_back({c, {a, b}});
    }
    sort(pre.begin(), pre.end());
    
    
    for (int i = 0; i < min(kth, edges); ++i) {
        int a = pre[i].second.first, b = pre[i].second.second, c = pre[i].first;
        graph[a][b] = graph[b][a] = c;
        //pre.push_back({c, {a, b}});
    }
    pre.clear();
    pre.shrink_to_fit();
    for (int i = 0; i <= vertices; ++i) {
        graph[i][i] = 0;
    }
 
 
    vector<ULLINT > v;
    for (int start = 1; start <= vertices; ++start) {
        dijkstra(start, vertices, graph);
        for (int end = start+1; end <= vertices; ++end) {
            v.push_back(graph[start][end]);
        }
    }
 
    sort(v.begin(), v.end());
    cout << v[kth-1] << endl;
/*
    for (vector<ULLINT >::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
*/
    return 0;
}
 