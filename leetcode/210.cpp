class Solution {
public:
    const int NOT_VISITED = 1;
    const int VISITING = 2;
    const int VISITED = 3;
    // visited, level
    vector<int> visited;
    vector<int> order;
    unordered_map<int, vector<int>> g;
    unordered_map<int, vector<int>> y;
    void build_graph(vector<vector<int>>& req) {
        for (auto r : req) {
            g[r[0]].push_back(r[1]);
            y[r[1]].push_back(r[0]);
        }
    }
    
    vector<int> getSearchOrder(int numCourses) {
        vector<int> ret;
        for (int i = 0; i < numCourses; ++i) {
            if (y.count(i) == 0) ret.push_back(i);       
        }
        return ret;
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
        order.push_back(start);
        
        return pass;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return {};
        build_graph(prerequisites);
        visited.resize(numCourses, NOT_VISITED);
        vector<int> searchList = getSearchOrder(numCourses);
        
        bool ans = true;
        for (auto r : searchList) {
            if (visited[r] == NOT_VISITED) {
                ans &= dfs(r);
            }
        }
        
        if (ans && order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
    
};
