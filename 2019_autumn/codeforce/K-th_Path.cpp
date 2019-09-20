#define DEBUG
const long long MAXN = 1e18;
#define INF long long 
#include <bits/stdc++.h>
 
 
using namespace std;
 

void dijkstra (int start, int total_node, vector<vector<INF >>& graph) {
    // pair for first is distance, second is index
    priority_queue<pair<INF, int > , vector<pair<INF ,int > >, greater<pair<INF , int >>> q;
    vector<int > had;
    q.push({graph[start][start], start});
    had.push_back(start);

    while (!q.empty()) {
        auto node = q.top().second;
        q.pop();
        // adjecent node of 'node'
        for (int i = 0; i < total_node; ++i) {
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
    scanf("%d%d%d", &vertices, &edges, &kth);
    //cin >> vertices >> edges >> kth;
    // weight , start , end 
    vector <pair<int , pair<int , int >>> preprocess;

    // sort by the weight
    for (int i = 0; i < edges; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //cin >> a >> b >> c;
        preprocess.push_back({c, {--a, --b}});
    }
    sort(preprocess.begin(), preprocess.end());
    
    vector<int > node_list;
    for (int i = 0; i < min(kth, edges); ++i) {
        node_list.push_back(preprocess[i].second.first);
        node_list.push_back(preprocess[i].second.second);
    }
    sort(node_list.begin(), node_list.end());
    // delete duplicate number
    node_list.resize(unique(node_list.begin(), node_list.end()) - node_list.begin());

    int size = node_list.size();
    vector <vector<INF >> graph(size, vector<INF > (size, MAXN));
    for (int i = 0; i < size; ++i) graph[i][i] = 0;

    // make new graph
    for (int i = 0; i < min(kth, edges); ++i) {
        // use the index in the node list to make new graph
        int x = lower_bound(node_list.begin(), node_list.end(), preprocess[i].second.first) - node_list.begin() ; 
        int y = lower_bound(node_list.begin(), node_list.end(), preprocess[i].second.second) - node_list.begin() ; 
        graph[x][y] = graph[y][x] = preprocess[i].first;
    }
    

/*
    use Floyd-Warshall algorithm
   for (int start = 0; start < size; ++start) {
        for (int middle = 0; middle < size; ++middle) {
            for (int end = 0; end < size; ++end) {
                graph[start][end] = min(graph[start][end], graph[start][middle]+graph[middle][end]);
            }
        }
    }
 
    vector<INF > v;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            v.push_back(graph[i][j]);
        }
    }
*/

    vector<INF > v;
    for (int start = 0; start < size; ++start) {
        dijkstra(start, size, graph);
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            v.push_back(graph[i][j]);
        }
    }

    sort(v.begin(), v.end());
    cout << v[kth-1] << endl;

    return 0;
}


