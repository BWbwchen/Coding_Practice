#define DEBUG
#define INDEX int
#define TYPE set
#define Vertex vector<pair<INDEX, INDEX>>
#include <bits/stdc++.h>

using namespace std;

unsigned long int vertex = 500;
// unsigned long int vertex = 5;
class solution {
   private:
    bool** map;
    INDEX kcore;
    // TYPE<INDEX> max_clique;
    vector<INDEX> max_clique;
    vector<INDEX> q_clique;
    vector<vector<INDEX>> C;
    Vertex S;

    TYPE<INDEX> ans_set(TYPE<INDEX> s, INDEX v) {
        // return s and neibor(v)
        TYPE<INDEX> to_return;
        for (TYPE<INDEX>::iterator it = s.begin(); it != s.end(); ++it) {
            if (map[v][*it]) to_return.insert(*it);
        }
        return to_return;
    }
    /*
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
    */
    void ColorSort(Vertex& r) {
        int j = 0;
        int maxno = 1;
        int min_k = max_clique.size() - q_clique.size() + 1;
        C[1].clear();
        C[2].clear();
        int k = 1;
        for (INDEX i = 0; i < r.size(); ++i) {
            int p = r[i].first;
            k = 1;
            while (and_set_bool(C[k], p)) k++;
            if (k > maxno) {
                maxno = k;
                C[maxno + 1].clear();
            }
            C[k].push_back(p);
            if (k < min_k) {
                r[j++].first = p;
            }
        }
        if (j > 0) r[j - 1].second = 0;
        if (min_k <= 0) min_k = 1;
        for (INDEX o = min_k; o <= maxno; ++o) {
            for (int i = 0; i < C[o].size(); ++i) {
                r[j].first = C[o][i];
                r[j].second = o;
                j++;
            }
        }
    }
    bool and_set_bool(vector<INDEX> r, INDEX p) {
        vector<INDEX> to_return;
        for (INDEX i = 0; i < r.size(); ++i) {
            if (map[p][r[i]]) {
                return true;
            }
        }
        return false;
    }
    Vertex and_set(Vertex r, INDEX p) {
        Vertex to_return;
        for (INDEX i = 0; i < r.size(); ++i) {
            if (map[p][r[i].first]) {
                to_return.push_back({r[i].first, r[i].second});
            }
        }
        return to_return;
    }
    // R
    // {index, degree?or color }
    void clique(Vertex R) {
        while (R.size()) {
            if (q_clique.size() + R.back().second > max_clique.size()) {
                q_clique.push_back(R.back().first);
                Vertex Rp;
                Rp = and_set(R, R.back().first);
                if (Rp.size()) {
                    ColorSort(Rp);
                    clique(Rp);
                } else if (q_clique.size() > max_clique.size()) {
                    max_clique = q_clique;
                }
                Rp.clear();
                q_clique.pop_back();
            } else
                return;
            R.pop_back();
        }
    }

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
        for (INDEX i = 0; i <= vertex; ++i) {
            C.push_back(vector<INDEX>(1));
        }
        S.resize(vertex+1);
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
        /*
        TYPE<INDEX> a, p, x;
        for (INDEX i = 0; i < vertex; ++i) {
            p.insert(i);
        }
        clique(a, p, x);
        */
        Vertex r;
        for (INDEX i = 0; i < vertex; ++i) {
            r.push_back({i, 0});
            for (INDEX j = 0; j < vertex; ++j) {
                if (map[i][j]) r[i].second++;
            }
        }
        // sort it !!
        sort(r.begin(), r.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });

        const int max_degree = r[0].second;
        for (int i = 0; i < max_degree; i++) r[i].second = i + 1;
        for (int i = max_degree; i < vertex; i++) r[i].second = max_degree + 1;

        clique(r);
    }
    void clique_ans() {
        cout << "clique ans " << endl;
        sort(max_clique.begin(), max_clique.end());
        for (vector<INDEX>::iterator it = max_clique.begin();
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

int main(int argc, char** argv) {
#ifdef DEBUG
    // freopen("in.in", "r", stdin);
    freopen("sample_input.txt", "r", stdin);
    // freopen("open_testcase_ds.txt", "r", stdin);
#endif
    solution t;
    t.input();
    clock_t start2 = clock();
    t.clique_starter();
    double time = ((double)(clock() - start2));
    cout << "clique finish Time (precise) = " << time / CLOCKS_PER_SEC << endl;
    t.clique_ans();
    /*
    t.k_core();
    */
    cout << "total finish Time (precise) = "
         << (double)(clock() - start2) / CLOCKS_PER_SEC << endl;

    return 0;
}
