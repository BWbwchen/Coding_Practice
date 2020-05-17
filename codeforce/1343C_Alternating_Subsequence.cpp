#include <algorithm>
#define DEBUG
#define MAXN 10000000
#define LLMIN -922337203685477580
#define ll long long int 
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        /*
         * make segment 
         * each segment contain same sign number
         * find each segment's max number as answer
         * sum them up
         */

        vector<int > v(n, 0);
        vector<bool > sign(n, 0);
        vector<vector<int > > segment;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] < 0) {
                sign[i] = false;
            } else {
                sign[i] = true;
            }
        }

        segment.push_back(vector<int > (1, v[0]));
        for (int i = 1; i < n; ++i) {
            if (sign[i] != sign[i-1]) {
                // new segment
                segment.push_back(vector<int > (1, v[i]));
            } else {
                segment.back().push_back(v[i]);
            }
        }

        /*
        cout << "=============================" << endl;
        for (auto each_segment : segment) {
            cout << "--------------" << endl;
            for (auto items : each_segment) {
                cout << items << " ";
            }
            cout << endl;
        }
        cout << "=============================" << endl;
        */

        vector<ll > final_ans;
        for (auto each_segment : segment) {
            ll temp_max = LLMIN;
            for (auto items : each_segment) {
                if (items > temp_max) {
                    temp_max = items;
                }
            }
            final_ans.push_back(temp_max);
        }


        ll ans = 0;
        for (auto items : final_ans) {
            ans += items;
        }
        cout << ans << endl;

    }



    return 0;
}
