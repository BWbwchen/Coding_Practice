#define DEBUG
#define INDEX int
#define TYPE set
#define Vertex vector<pair<INDEX, INDEX>>
#include <bits/stdc++.h>
#include <unistd.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

unsigned long int vertex = 500;
// unsigned long int vertex = 5;
class solution {
   private:
    INDEX level;
    unsigned long long int pk;
    float TimeLimit;
    bool **map;
    INDEX kcore;
    vector<INDEX> max_clique;
    vector<INDEX> q_clique;
    vector<vector<INDEX>> C;
    vector<INDEX> num_edges;
    vector<INDEX> adj;
    vector<INDEX> core;
    Vertex S;

    void ColorSort(Vertex &r) {
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
    void my_sort(Vertex &a) {
        sort(a.begin(), a.end(), [](const auto &lhs, const auto &rhs) {
            return lhs.second > rhs.second;
        });
    }
    void init_color(Vertex &r) {
        const int max_degree = r[0].second;
        for (int i = 0; i < max_degree; i++) r[i].second = i + 1;
        for (int i = max_degree; i < vertex; i++) r[i].second = max_degree + 1;
    }
    // R
    // {index, degree?or color }
    void clique(Vertex R) {
        S[level].first = S[level].first + S[level - 1].first - S[level].second;
        S[level].second = S[level - 1].first;
        while (R.size()) {
            if (q_clique.size() + R.back().second > max_clique.size()) {
                q_clique.push_back(R.back().first);
                Vertex Rp;
                Rp = and_set(R, R.back().first);
                if (Rp.size()) {
                    if ((float)S[level].first / ++pk < TimeLimit) {
                        // sort degree
                        my_sort(Rp);
                    }
                    ColorSort(Rp);
                    S[level].first++;
                    level++;
                    clique(Rp);
                    level--;
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
    void init_k() {
        vector<INDEX> temp_num_edges(vertex + 1);
        temp_num_edges[0] = 0;
        int m = 0;
        for (int i = 0; i < vertex; ++i) {
            m += num_edges[i];
            temp_num_edges[i + 1] = m;
        }
        adj.resize(m);
        for (int i = 0; i < vertex + 1; ++i) {
            num_edges[i] = temp_num_edges[i];
        }

        for (int i = 0; i < vertex; ++i) {
            for (int j = i + 1; j < vertex; ++j) {
                if (map[i][j]) {
                    adj[temp_num_edges[i]++] = j;
                    adj[temp_num_edges[j]++] = i;
                }
            }
        }

        for (int i = 0; i < vertex; ++i) {
            sort(adj.begin() + num_edges[i], adj.begin() + num_edges[i + 1],
                 [](const auto &lhs, const auto &rhs) { return lhs > rhs; });
        }
    }

   public:
    solution(int k) {
        level = 0;
        pk = 0;
        TimeLimit = 0.025f;
        kcore = k;

        map = new bool *[vertex];
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
        S.resize(vertex + 1);
        num_edges.resize(vertex + 1, 0);
        core.resize(vertex, 0);
    }
    void input(char *file) {
        freopen(file, "r", stdin);
        INDEX a, b;
        INDEX max = -1;
        while (cin >> a >> b) {
            if (max < a) max = a;
            else if (max < b) max = b;

            map[a][b] = true;
            map[b][a] = true;
            num_edges[a]++;
            num_edges[b]++;
        }
        vertex = max;
    }
    void clique_starter() {
        Vertex r;
        for (INDEX i = 0; i < vertex; ++i) {
            r.push_back({i, 0});
            for (INDEX j = 0; j < vertex; ++j) {
                if (map[i][j]) r[i].second++;
            }
        }
        // sort it !!
        my_sort(r);

        init_color(r);

        for (int i = 0; i < r.size() + 1; i++) {
            S[i].first = 0;
            S[i].second = 0;
        }
        level = 1;

        clique(r);
    }
    void clique_ans() {
        ofstream clique_stream("clique.txt");
        sort(max_clique.begin(), max_clique.end());
        for (vector<INDEX>::iterator it = max_clique.begin();
             it != max_clique.end(); ++it) {
            clique_stream << *it << endl;
        }
        clique_stream.close();
    }
    void BZ_kCores() {
        init_k();
        core.resize(vertex, 0);

        // Two arrays of size n
        vector<INDEX> vert(vertex, 0);
        vector<INDEX> pos(vertex, 0);

        // Maximum degree
        int maxDeg = 0;

        // deg[i] -- contains degree of vertex i
        for (long i = 0; i < vertex; i++) {
            core[i] = num_edges[i + 1] - num_edges[i];
            if (core[i] > maxDeg) maxDeg = core[i];
        }

        // Used for bin-sort -- is of size maxDeg + 1
        vector<INDEX> bin(maxDeg + 1);

        // Sort the vertices by increasing degree using bin-sort
        // Count number of vertices with each degree in 0...maxDeg
        for (long i = 0; i < vertex; i++) bin[core[i]]++;

        unsigned int start = 0;
        for (int d = 0; d < maxDeg + 1; d++) {
            unsigned int num = bin[d];
            bin[d] = start;  // Start index of vertex in vert with degree d
            start = start + num;
        }

        // Do bin-sort of the vertices
        // vert -- contains the vertices in sorted order of degree
        // pos -- contains the positon of a vertex in vert array
        for (long i = 0; i < vertex; i++) {
            pos[i] = bin[core[i]];
            vert[pos[i]] = i;
            bin[core[i]]++;
        }

        for (int d = maxDeg; d >= 1; d--) bin[d] = bin[d - 1];
        bin[0] = 0;

        // kcores computation
        for (long i = 0; i < vertex; i++) {
            // Process the vertices in increasing order of degree
            INDEX v = vert[i];
            for (INDEX j = num_edges[v]; j < num_edges[v + 1]; j++) {
                // TODO;
                INDEX u = adj[j];
                if (core[u] > core[v]) {
                    // Swap u with the first vertex in bin[du]
                    unsigned int du = core[u];
                    unsigned int pu = pos[u];
                    unsigned int pw = bin[du];
                    unsigned int w = vert[pw];

                    if (u != w) {
                        pos[u] = pw;
                        vert[pu] = w;
                        pos[w] = pu;
                        vert[pw] = u;
                    }

                    // Increase the starting index of bin du
                    bin[du]++;

                    // Decrease degree of u -- so u is in previous bin now
                    core[u]--;
                }
            }
        }

        // print ans
        vert.clear();
        pos.clear();
    }
    void kcore_ans() {
        ofstream kcore_stream("kcore.txt");
        for (int i = 0; i < vertex; ++i) {
            if (core[i] >= kcore) kcore_stream << i << " " << core[i] << endl;
        }
        kcore_stream.close();
    }
};

int main(int argc, char **argv) {
    //--------------input argument---------------//
    int opt;
    char *file_str;
    int k_core = 0;
    if (argc != 3) {
        fprintf(stderr,
            "usage : ./clique_find (graph file) (k core number)\n");
        exit(1);
    }
    /*
    while ((opt = getopt(argc, argv, "f:k:")) != -1) {
        switch (opt) {
            case 'f':
                cout << optarg << endl;
                file_str = optarg;
                break;
            case 'k':
                cout << optarg << endl;
                k_core = stoi(optarg);
                break;
            default:
                fprintf(stderr,
                        "usage : ./clique_find -f (graph file) -k (k core "
                        "number)\n");
                exit(1);
        }
    }
    */

    //--------------input argument---------------//
    solution t(atoi(argv[2]));
    t.input(argv[1]);

    //------------------thread-------------------//
    auto start = high_resolution_clock::now();
    thread t1(&solution::clique_starter, &t);
    thread t2(&solution::BZ_kCores, &t);
    t1.join();
    t2.join();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "time : " << duration.count() << endl;
    //t.clique_starter();
    //t.BZ_kCores();
    
    start = high_resolution_clock::now();
    t.clique_ans();
    t.kcore_ans();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "IO time : " << duration.count() << endl;

    return 0;
}
