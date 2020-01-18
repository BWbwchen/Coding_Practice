#define DEBUG
#define INDEX unsigned long int
#include <bits/stdc++.h>

using namespace std;

unsigned long int vertex = 500;
//unsigned long int vertex = 5;
class solution {
   private:
    bool **map;
    INDEX kcore;

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
            for (set<INDEX>::iterator it = a.begin(); it != a.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
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
        /*
        cout << "this is map \n";
        for (INDEX i = 0; i < vertex; ++i) {
            for (INDEX j = 0; j < vertex; ++j) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
    void clique_starter() {
        freopen("clique.txt", "w", stdout);
        set<INDEX> a, p, x;
        for (INDEX i = 0; i < vertex; ++i) {
            p.insert(i);
        }
        clique(a, p, x);
    }
    void debug (vector<pair<INDEX, INDEX>> a) {
        cout << "---------------debug-------------" << endl;
        for (INDEX i = 0; i < a.size(); ++i) {
            cout << "core number is " << a[i].second << " core is " << a[i].first << endl;
        }
    }
    void k_core () {
        freopen("k_core.txt", "w", stdout);
        vector<INDEX> core(vertex, 0);
        // computer the degrees of vertices
        // {degree, index}
        vector<pair<INDEX, INDEX>> degree(vertex, {0, 0});
        for (INDEX i = 0; i < vertex; ++i) {
            degree[i].second = i;
            for (INDEX j = 0; j < vertex; ++j) {
                if (map[i][j]) 
                    degree[i].first++;
            }
        }
        // order the set increasing by degree
        sort(degree.begin(), degree.end());

        for (INDEX i = 0; i < vertex; ++i) {
            //cout << "core " << degree[i].second << " is " << degree[i].first << endl;
            core[degree[i].second] = degree[i].first;
            for (INDEX j = 0; j < vertex; ++j) {
                //printf("map[%d][%d] is : %d\n", degree[i].second, j, map[degree[i].second][j]);
                // adjcent
                if (map[degree[i].second][degree[j].second]) {
                    if (degree[j].first > degree[i].first) {
                        degree[j].first--;
                        sort(degree.begin()+i+1, degree.end());
                        //debug(degree);
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
#endif
    solution t;
    t.input();
    t.clique_starter();
    t.k_core();

    return 0;
}
