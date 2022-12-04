class Solution {
public:
    const int MAXN = 2147483647;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0 ; i < roads.size(); ++i) {
            graph[roads[i][0]-1].emplace_back(make_pair(roads[i][1]-1, roads[i][2]));
            graph[roads[i][1]-1].emplace_back(make_pair(roads[i][0]-1, roads[i][2]));
        }
        
        // dfs 
        vector<bool> done(n, false);
        
        int _min = 2147483647;
        stack<int> st;
        st.push(0);
        while(!st.empty()) {
            auto top = st.top(); 
            st.pop();
            
            if (!done[top]){
                done[top] = true; 
                for (auto &np: graph[top]) {
                    _min = min(_min, np.second); 
                    if (!done[np.first]) 
                        st.push(np.first);
                }
            } 
                
        }
        
        return _min;
    }
};
