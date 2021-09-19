class Solution {
public:
    const int NOT_VISITED = 1;
    const int VISITING = 2;
    const int VISITED = 3;
    // visited, level
    vector<int> visited;
    unordered_map<int, vector<int>> g;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return false;
        build_graph(prerequisites);
        visited.resize(numCourses, NOT_VISITED);
        
        bool ans = true;
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == NOT_VISITED) {
                ans &= dfs(i);
            }
        }
        return ans;    
    }
    
    void build_graph(vector<vector<int>>& req) {
        for (auto r : req) {
            g[r[0]].push_back(r[1]);
        }
    }
    
    bool dfs(int start) {
        auto visitedInfo = visited[start];
        
        if (visitedInfo == VISITING)  return false;
        
        if (visitedInfo == VISITED)  return true;
        
        visited[start] = VISITING;
        
        bool pass = true;
        if (g.find(start) != g.end()) {
            for (auto child : g[start]) {
                pass &= dfs(child); 
            }
        }
        
        visited[start] = VISITED;
        
        return pass;
    }
    
};
