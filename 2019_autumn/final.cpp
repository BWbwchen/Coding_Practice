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
        cout << "l;aksdjfal;skdfjldkfjas;ldkfjasl;kdfj;aslkdjf" << endl;
        clique(a, p, x);
    }
    set<INDEX> new_set(set<INDEX> s, set<INDEX> ans, INDEX v) {
        set<INDEX> newset = s;
        // check if it conneted to all node in answer set
        for (set<INDEX>::iterator it = ans.begin(); it != ans.end(); ++it) {
            if (!map[v][*it] && !map[*it][v]) return newset;
        }
        newset.insert(v);
        return newset;
    }
    void clique(set<INDEX> a, set<INDEX> p, set<INDEX> x) {
        if (p.size() == 0) {
            cout << "this is a clique" << endl;
            for (set<INDEX>::iterator it = a.begin(); it != a.end(); ++it) {
                cout << *it << endl;
            }
        }
        for (INDEX i = 0; i < vertex; ++i) {
            if (p.find(i) != p.end()) {
                set<INDEX> new_p = p;
                new_p.erase(i);
                clique(new_set(a, a, i), new_p, new_set(x, a, i));
                p.erase(i);
                x.insert(i);
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
