#define DEBUG
#include <bits/stdc++.h>
#define ll unsigned long long int
#define PASS    1
#define CLEAN   2
#define FAIL    3
#define MAXN    10e16 + 1

using namespace std;


class problem {
    private :
        int n;
        vector<int > l;
        vector<int > r;
        vector<int > val;
        vector<vector<int >> rg;
        // dp(l, r) = max num of segment in range [l, r]
        vector<vector<int >> dp;

        void compress_coordinate() {
            sort(val.begin(), val.end());
            val.resize(unique(val.begin(), val.end()) - val.begin());

            for (int i = 0; i < l.size(); ++i) {
                l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
                r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin();
            }
            dp.resize(val.size(), vector<int>(val.size(), -1));
        }

        int go_dp (int left, int right) {
            // invalid left and right
            if (left > right) return 0;
            if (dp[left][right] != -1) return dp[left][right];
            // if [left, right] cover the entire segment, 
            // add 1 !(segment [left, right])
            bool entire_segment = 0;
            for (auto _right : rg[left]) {
                if (_right == right) entire_segment = 1;
            }
            dp[left][right] = max(dp[left][right], 
                                    entire_segment + go_dp(left+1, right));

            // range dp transition
            // dp(l, r) = 1 (self) + dp(l, middle) + dp(middle + 1, right)
            for (auto _middle : rg[left]) {
                int new_dp = 0;
                if (_middle + 1 > right) new_dp = 0;
                else new_dp = entire_segment + go_dp(left, _middle) + go_dp(_middle + 1, right);
                dp[left][right] = max(dp[left][right], new_dp);
            }

            return dp[left][right];
        }
    public :
        problem () {
            n = 0;
            l.clear();
            r.clear();
            val.clear();
            dp.clear();
            rg.clear();
        }
        void input () {
            cin >> n;
            l.resize(n);
            r.resize(n);
            for (int i = 0; i < n; ++i) {
                cin >> l[i] >> r[i];
                val.push_back(l[i]);
                val.push_back(r[i]);
            }
            compress_coordinate();
            rg.resize(val.size());
            for (int i = 0; i < n; ++i) {
                rg[l[i]].push_back(r[i]);
            }
        }
        void solve () {
            cout << go_dp(0, val.size()-1) << endl;
        }
};


int main () {
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int n_case;
    cin >> n_case;
    while (n_case--) {
        problem t;
        t.input();
        t.solve();
    }
    return 0;
}
