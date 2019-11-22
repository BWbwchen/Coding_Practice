#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>

using namespace std;

class Graph {
    private :
        int **graph;
        int vertex;
        vector<bool> visited;
    public :
        Graph (int total) {
            vertex = total;
            graph = new int* [vertex];  
            for (int i = 0; i < vertex; ++i) {
                graph[i] = (int *)new int* [vertex];
            }
            // initial not connected
            for (int i = 0; i < vertex; ++i) {
                for (int j = 0; j < vertex; ++j) {
                    if (i == j) graph[i][j] = 0;
                    else graph[i][j] = MAXN;
                }
            }
            visited.resize(vertex, false);
        }
        void build () {
            int total_path;
            cin >> total_path;
            for (int i = 0; i < total_path; ++i) {
                int from, to;
                cin >> from >> to ;
                cin >> graph[from][to];
                graph[to][from] = graph[from][to];
            }
        }
        void dfs () {
            cout << "recursive : ";
            dfs_recursive(0);
            cout << endl;
            /* --------------------------*/
            fill(visited.begin(), visited.end(), false);
            cout << "nonrecursive : ";
            dfs_nonrecursive();
            cout << endl;
        }
        void dfs_recursive(int index) {
            visited[index] = true;
            cout << (char)(index+'A') << "-> ";
            for (int i = 0; i < vertex; ++i) {
                if (graph[index][i] != MAXN && visited[i] == false) {
                    dfs_recursive(i);
                }
            }
        }
        void dfs_nonrecursive() {
            // TODO : need debug
            stack<int > buffer;
            buffer.push(0);
            visited[0] = true;
            while (!buffer.empty()) {
                int top = buffer.top();
                cout << (char)(top+'A') << "-> ";
                buffer.pop();
                // push the adjecent node into the stack
                for (int i = vertex-1; i >= 0; --i) {
                    if (graph[top][i] != MAXN && visited[i] == false) {
                        visited[i] = true;
                        buffer.push(i);
                    }
                }
            }
        }

        void bfs () {


        }

};

int main () 
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 
    int total;
    cin >> total;
    Graph t(total);

    t.build();
    t.dfs();
    

    return 0;
}

