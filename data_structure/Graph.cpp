#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>
#define PRIM 1

using namespace std;
class Node {
    public : 
        int index;
        int parent; /* -1 for root */
        int key;
        Node () {
            index = 0; 
            parent = -1;
            key = MAXN;
        }
        Node (int i , int p = -1, int k = MAXN) {
            index = i;
            parent = p;
            key = k;
        }
};

class Graph {
    private :
        int **graph;
        int vertex;
        vector<bool> visited;
        Node *node;
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
            node = new Node [vertex];
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
            // O(n^2)
            stack<int > buffer;
            buffer.push(0);
            while (!buffer.empty()) {
                int top = buffer.top();
                buffer.pop();
                if (!visited[top]) {
                    // visit top
                    cout << (char)(top+'A') << "-> ";
                    visited[top] = true;
                    // push the adjecent node into the stack
                    for (int i = vertex-1; i >= 0; --i) {
                        if (graph[top][i] != MAXN && visited[i] == false) {
                            buffer.push(i);
                        }
                    }
                }
            }
        }

        void bfs () {
            cout << "bfs " << endl;
            vector<bool> done; 
            done.resize(vertex, false);
            
            queue<int > q;
            q.push(0);
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                if (!done[top]) { 
                    cout << (char)(top+'A') << "-> ";
                    done[top] = true;
                    for (int i = 0; i < vertex; ++i) {
                        if (graph[top][i] != MAXN && done[i] == false) {
                            q.push(i);
                        }
                    }
                }
            }
        }
        void spanning_tree (int method) {
            if (method == PRIM) prim();
        }
        /*
        bool cmp (Node a, Node b) {
            return a.key > b.key;
        }
        */
        Node Min_Node (vector<Node >& my_pq) {
            auto cmp = [](Node a, Node b) {return a.key < b.key;};
            sort(my_pq.begin(), my_pq.end(), cmp); 
            Node temp = my_pq[my_pq.size()-1];
            my_pq.pop_back();
            return temp;
        }
        void prim () {
            // initial
            vector<bool > gone(vertex);
            fill(gone.begin(), gone.end(), false);
            for (int i = 0; i < vertex; ++i) {
                node[i].index = i;
                node[i].key = MAXN;
                node[i].parent = -1;
            }
            node[0].key = 0;
            
            // prim
           for (int i = 0; i < vertex; ++i) {
                // find the min key node to deal 
                int min = MAXN;
                int min_index = -1;
                for (int j = 0; j < vertex; ++j) {
                    if (!gone[j] && min > node[j].key ) {
                        min = node[j].key;
                        min_index = j;
                    }
                }
                gone[min_index] = true;
                // update the near node's key
                for (int j = 0; j < vertex; ++j) {
                    if (graph[min_index][j] != MAXN &&
                        !gone[j] &&
                        node[j].key > graph[min_index][j]){
                        node[j].key = graph[min_index][j];
                        node[j].parent = min_index;
                    }
                }
           }

            // print result
            for (int i = 0; i < vertex; ++i) {
                cout << (char)(node[i].parent + 'A') << "--> " << (char)(node[i].index + 'A') << endl;
            }
            
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
    //t.dfs();
    //t.bfs();
    t.spanning_tree(PRIM); 
    

    return 0;
}

