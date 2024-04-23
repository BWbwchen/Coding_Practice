class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Since there are at most 2 nodes as the centre(A tree node will have at most 2 neighbor, If 3 centre, the middle one will become new centre).
        // How to find the centre?
        // remove the leaf node layer by layer, the remain 1 or 2 nodes are the centre.
        // How to detect a node is a leaf node or not?
        // keep tracking the edge of each node!
        if (n == 1)
            return {0};

        vector<int> in_degree(n, 0);
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            in_degree[e[0]]++;
            in_degree[e[1]]++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        for (int node = 0; node < in_degree.size(); ++node) {
            if (in_degree[node] == 1) // leaf node
                q.push(node);
        }

        int leaf_node = 0;
        while(n - leaf_node > 2) { // at most 2 centres
            // remove leaf node
            int tmp_leaf_node = q.size();
            leaf_node += tmp_leaf_node;
            for (int i = 0; i < tmp_leaf_node; ++i) {
                int leaf = q.front();
                q.pop();

                for (auto neighbor : graph[leaf]) {
                    if (--in_degree[neighbor] == 1) 
                        q.push(neighbor);
                }
            }
        }

        vector<int> ret;
        while(!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
