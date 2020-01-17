#define DEBUG
#define INDEX unsigned long int
#include <bits/stdc++.h>

using namespace std;

unsigned long int vertex = 5;
class solution {
   private:
    bool **map;

   public:
    solution() {
        map = new bool*[vertex];
        for (INDEX i = 0; i < vertex; ++i) {
            map[i] = new bool[vertex];
        }
        for (INDEX i = 0; i < vertex; ++i) {
            for (INDEX j = 0; j < vertex; ++j) {
                map[i][j] = false;
            }
        }
        //for (INDEX i = 0; i < vertex; ++i) map[i][i] = true;
    }
    void input() {
        INDEX a, b;
        while (cin >> a >> b) {
            map[a][b] = true;
            map[b][a] = true;
        }
    }
    void clique_starter() {
        set<INDEX> a, p, x;
        for (INDEX i = 0; i < vertex; ++i) {
            p.insert(i);
        }
        clique(a, p, x);
    }
    set<INDEX> ans_set(set<INDEX> s, set<INDEX> ans, INDEX v) {
        set<INDEX> newset = s;
        // check if it conneted to all node in answer set
        for (set<INDEX>::iterator it = ans.begin(); it != ans.end(); ++it) {
            if (!map[v][*it]) return s;
        }
        newset.insert(v);
        return newset;
    }
    void clique(set<INDEX> a, set<INDEX> p, set<INDEX> x) {
        if (p.size() == 0 ) {
            for (set<INDEX>::iterator it = a.begin(); it != a.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
            return;
        }
        for (INDEX i = 0; i < vertex; ++i) {
            if (p.find(i) != p.end() && x.find(i) == x.end()) {
                set<INDEX> new_a = ans_set(a, a, i);
                set<INDEX> new_p = p;
                set<INDEX> new_x = ans_set(x, a, i);

                new_p.erase(i);

                clique(new_a, new_p, new_x);
                //p.erase(i);
                //x.insert(i);
                if (new_a.find(i) != new_a.end()) x.insert(i); 
            }
        }
    }
};

int main(int argc, char **argv) {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    solution t;
    t.input();
    t.clique_starter();

    return 0;
}
