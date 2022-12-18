class Solution {
public:
    bool isPossible(int n, vector<vector<int>> &edges) {
        vector<unordered_set<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0] - 1].emplace(e[1] - 1);
            graph[e[1] - 1].emplace(e[0] - 1);
        }

        vector<int> odd;

        for (int i = 0; i < n; ++i) {
            if (graph[i].size() % 2 == 1)
                odd.emplace_back(i);
        }

        if (odd.size() == 0) {
            return true;
        }

        if (odd.size() == 2) {
            for (auto &g : graph) {
                if (!g.count(odd[0]) && !g.count(odd[1]))
                    return true;
            }
            return false;
        }

        if (odd.size() == 4) {
            auto &a = odd[0];
            auto &b = odd[1];
            auto &c = odd[2];
            auto &d = odd[3];
            if (!graph[a].count(c) && !graph[b].count(d) ||
                !graph[a].count(b) && !graph[c].count(d) ||
                !graph[a].count(d) && !graph[c].count(b)) {
                return true;
            }
            return false;
        }

        return false;
    }
};
