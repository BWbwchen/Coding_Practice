#define DEBUG
#define MAXN 1e9+10
#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif
    // TODO : need to preprocess the data 
    int vertices, edges, kth;
    cin >> vertices >> edges >> kth;
    vector<int > record;
    int graph[vertices+1][vertices+1] ;
    for (int i = 0; i <= vertices; ++i) {
        for (int j = 0; j <= vertices; ++j) {
            graph[i][j] = MAXN;
        }
    }
    // initialize map
    for (int i = 0; i < edges; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }
    for (int i = 0; i <= vertices; ++i) {
        graph[i][i] = 0;
    }
    
    // Floyd-Warshall algorithm
    for (int start = 1; start <= vertices; ++start) {
        for (int middle = 1; middle <= vertices; ++middle) {
            for (int end = 1; end <= vertices; ++end) {
                if (graph[start][end] > graph[start][middle] + graph[middle][end] ){
                    graph[start][end] = graph[start][middle] + graph[middle][end];
                }
            }
        }
    }

    for (int i = 1; i <= vertices; ++i) {
        for (int j = i+1; j <= vertices; ++j) {
            record.push_back(graph[i][j]);
        }
    }

    sort(record.begin(), record.end());
    cout << record[kth-1] << endl;
 
    return 0;
}


