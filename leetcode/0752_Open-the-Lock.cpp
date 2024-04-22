class Solution {
public:
    struct si {
        string s;
        int steps;
    };
    string rotate(string s, int i, int dir) {
        s[i] = (((s[i] - '0') + dir + 10) % 10) + '0';
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        // bfs with graph, which consist of 10000 nodes.
        // each node has 8 neighbors.
        queue<si> q;
        vector<int> dirs = {-1, 1};

        unordered_set<string> dead;
        for (auto &s : deadends) {
            dead.insert(s);
        }

        if (dead.count("0000") <= 0)
            q.push(si(
                "0000",
                0
            ));

        unordered_set<string> found;
        found.insert("0000");

        bool is_valid = false;
        int ret = std::numeric_limits<int>::max();

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (top.s == target) {
                return top.steps;
            }

            for (int i = 0; i < 4; ++i) {
                for (auto dir : dirs) {
                    auto new_str = rotate(top.s, i, dir);
                    if (dead.count(new_str) <= 0 && found.count(new_str) <= 0) {
                        q.push(si(new_str, top.steps+1));
                        found.insert(new_str);
                    }
                }
            }
        }


        return -1;
    }
};
