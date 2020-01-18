#define DEBUG
#define INDEX unsigned long int
#define TYPE set
#include <bits/stdc++.h>

using namespace std;

unsigned long int vertex = 500;
// unsigned long int vertex = 5;
class solution {
   private:
    bool **map;
    INDEX kcore;
    TYPE<INDEX> max_clique;

    TYPE<INDEX> ans_set(TYPE<INDEX> s, INDEX v) {
        // return s and neibor(v)
        TYPE<INDEX> to_return;
        for (TYPE<INDEX>::iterator it = s.begin();
             it != s.end(); ++it) {
            if (map[v][*it]) to_return.insert(*it);
        }
        return to_return;
    }
    void clique(TYPE<INDEX> a, TYPE<INDEX> p, TYPE<INDEX> x) {
        if (p.size() == 0 && x.size() == 0) {
            if (a.size() > max_clique.size()) max_clique = a;
            return;
        }

        TYPE<INDEX> old_p = p;
        // try with pivot
        INDEX pivot_u;
        if (p.size() == 0) pivot_u = *(x.begin());
        else pivot_u = *(p.begin());
        for (TYPE<INDEX>::iterator it = p.begin();
            it != p.end(); ++it) {
            if (map[*it][pivot_u]) continue;
            TYPE<INDEX> new_a = a;
            if (new_a.find(*it) == new_a.end()) new_a.insert(*it);
            TYPE<INDEX> new_p = ans_set(p, *it);
            TYPE<INDEX> new_x = ans_set(x, *it);

            clique(new_a, new_p, new_x);
            if (p.find(*it) != p.end()) p.erase(it);
            if (x.find(*it) == x.end()) x.insert(*it);
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
        TYPE<INDEX> a, p, x;
        for (INDEX i = 0; i < vertex; ++i) {
            p.insert(i);
        }
        clique(a, p, x);
    }
    void clique_ans() {
        for (TYPE<INDEX>::iterator it = max_clique.begin();
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
//        freopen("k_core.txt", "w", stdout);
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
//    freopen("in.in", "r", stdin);
    freopen("sample_input.txt", "r", stdin);
    // freopen("open_testcase_ds.txt", "r", stdin);
#endif
    solution t;
    t.input();
    clock_t start2 = clock();
    t.clique_starter();
    double time = ((double)(clock() - start2));
    t.clique_ans();
    cout << "Time (precise) = " << time / CLOCKS_PER_SEC << endl;
    t.k_core();

    return 0;
}
