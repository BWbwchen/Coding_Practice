// Maximum flow
// By Ford fulkerson method with BFS (Edmonds-Karp algorithm)
#include <bits/stdc++.h>
#define NONE -1
#define MAXN 2e9

using namespace std;

class Solve {
private:
  int num_vertex;
  vector<vector<int>> graph;
  vector<vector<int>> residual_graph;
  vector<int> aug_path;

  int getAugmentingPathMinCapacity(int start, int end) {
    int now = end;
    int c = MAXN;
    while (aug_path[now] != NONE) {
      int predecessor = aug_path[now];
      c = min(c, residual_graph[predecessor][now]);
      now = predecessor;
    }
    return c;
  }
  bool existAugmentingPath(int start, int end) {
    // BFS
    fill(aug_path.begin(), aug_path.end(), NONE);

    queue<int> q;
    vector<bool> visited(num_vertex, false);
    q.push(start);

    visited[start] = true;
    aug_path[start] = NONE;

    while (!q.empty()) {
      int now = q.front();
      q.pop();

      for (int i = 0; i < num_vertex; ++i) {
        if (residual_graph[now][i] != 0 && !visited[i]) {
          visited[i] = true;
          q.push(i);
          aug_path[i] = now;
        }
      }
    }

    return visited[end];
    // return aug_path[end] != NONE;
  }
  void AddFlow(int start, int end, int capacity) {
    int now = end;
    while (aug_path[now] != NONE) {
      int predecessor = aug_path[now];
      residual_graph[predecessor][now] -= capacity;
      now = predecessor;
    }
  }

public:
  Solve() { num_vertex = 0; }
  Solve(int n) {
    num_vertex = n;
    graph = vector<vector<int>>(n, vector<int>(n, 0));
    residual_graph = vector<vector<int>>(n, vector<int>(n, 0));
    aug_path = vector<int>(n, NONE);
  }
  void AddEdge(int start, int end, int capacity) {
    if (start >= num_vertex || end >= num_vertex) {
      throw std::invalid_argument("No such node");
      return;
    }
    graph[start][end] = capacity;
    residual_graph[start][end] = capacity;
  }

  int FordFulkerson(int start, int end) {
    int total_flow = 0;
    while (existAugmentingPath(start, end)) {
      int max_flow = getAugmentingPathMinCapacity(start, end);
      AddFlow(start, end, max_flow);
      total_flow += max_flow;
    }
    return total_flow;
  }
};

int main() {
  Solve g(6);
  g.AddEdge(0, 1, 9);
  g.AddEdge(0, 3, 9);
  g.AddEdge(1, 2, 3);
  g.AddEdge(1, 3, 8);
  g.AddEdge(2, 4, 2);
  g.AddEdge(2, 5, 9);
  g.AddEdge(3, 2, 7);
  g.AddEdge(3, 4, 7);
  g.AddEdge(4, 2, 4);
  g.AddEdge(4, 5, 8);

  cout << "Maximum flow is : " << g.FordFulkerson(0, 5) << endl;
  return 0;
}
