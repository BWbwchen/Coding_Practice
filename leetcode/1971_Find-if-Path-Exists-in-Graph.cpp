class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;
        stack<int> st;
        st.push(source);
        bool ret = false;

        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        while (!st.empty()) {
            auto top = st.top();
            st.pop();

            if (!visited[top]) {
                visited[top] = true;
                for (auto neigh : adj[top]) {
                    st.push(neigh);
                    if (neigh == destination) {
                        ret = true;
                        goto found;
                    }
                }
            }
        }
found:
        return ret;
    }
};
