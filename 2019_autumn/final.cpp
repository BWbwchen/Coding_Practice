#define DEBUG
#define INDEX unsigned long int
#include <bits/stdc++.h>

using namespace std;

unsigned long int vertex = 500;
// unsigned long int vertex = 5;
class solution {
   private:
    bool **map;
    INDEX kcore;
    set<INDEX> max_clique;

    set<INDEX> ans_set(set<INDEX> s, INDEX v) {
        // return s and neibor(v)
        set<INDEX> to_return;
        for (INDEX i = 0; i < vertex; ++i) {
            if (map[v][i] && s.find(i) != s.end()) to_return.insert(i);
        }
        return to_return;
    }
    void clique(set<INDEX> a, set<INDEX> p, set<INDEX> x) {
        if (p.size() == 0 && x.size() == 0) {
            if (a.size() > max_clique.size()) max_clique = a;
            return;
        }
        for (INDEX i = 0; i < vertex; ++i) {
            if (p.find(i) != p.end()) {
                set<INDEX> new_a = a;
                new_a.insert(i);
                set<INDEX> new_p = ans_set(p, i);
                set<INDEX> new_x = ans_set(x, i);

                clique(new_a, new_p, new_x);
                p.erase(i);
                x.insert(i);
            }
        }
    }

   public:
    solution() {
        map = new bool *[vertex];
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
            if (b == -100) {
                kcore = a;
                break;
            }
            map[a][b] = true;
            map[b][a] = true;
        }
    }
    void clique_starter() {
        // freopen("clique.txt", "w", stdout);
        set<INDEX> a, p, x;
        for (INDEX i = 0; i < vertex; ++i) {
            p.insert(i);
        }
        clique(a, p, x);

        for (set<INDEX>::iterator it = max_clique.begin();
             it != max_clique.end(); ++it) {
            cout << *it << endl;
        }
    }
    void debug(vector<pair<INDEX, INDEX>> a) {
        cout << "---------------debug-------------" << endl;
        for (INDEX i = 0; i < a.size(); ++i) {
            cout << "core number is " << a[i].second << " core is "
                 << a[i].first << endl;
        }
    }
    void k_core() {
        freopen("k_core.txt", "w", stdout);
        vector<INDEX> core(vertex, 0);
        // computer the degrees of vertices
        // {degree, index}
        vector<pair<INDEX, INDEX>> degree(vertex, {0, 0});
        for (INDEX i = 0; i < vertex; ++i) {
            degree[i].second = i;
            for (INDEX j = 0; j < vertex; ++j) {
                if (map[i][j]) degree[i].first++;
            }
        }
        // order the set increasing by degree
        sort(degree.begin(), degree.end());

        for (INDEX i = 0; i < vertex; ++i) {
            core[degree[i].second] = degree[i].first;
            for (INDEX j = 0; j < vertex; ++j) {
                // adjcent
                if (map[degree[i].second][degree[j].second]) {
                    if (degree[j].first > degree[i].first) {
                        degree[j].first--;
                        sort(degree.begin() + i + 1, degree.end());
                    }
                }
            }
        }

        // print the answer
        for (INDEX i = 0; i < vertex; ++i) {
            if (core[i] >= kcore) cout << i << " " << core[i] << endl;
        }
    }
};

int main(int argc, char **argv) {
#ifdef DEBUG
    //freopen("in.in", "r", stdin);
    freopen("sample_input.txt", "r", stdin);
    //freopen("open_testcase_ds.txt", "r", stdin);
#endif
    solution t;
    t.input();
    clock_t start2 = clock();
    t.clique_starter();
    cout << "Time (precise) = " << ((double)(clock() - start2)) / CLOCKS_PER_SEC
         << endl;
    t.k_core();

    return 0;
}
