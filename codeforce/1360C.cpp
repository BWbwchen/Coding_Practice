#include <cstdio>
#include <vector>
#define DEBUG
#define MAXN 10000000
#define MULTIPLE(i, j, k) lake[i] * lake[j] * lake[k]
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ; 
    cin >> n ;
    while (n--) {
        int a ;
        cin >> a;
        vector<int > v(a, 0);
        //for (auto &it : v) cin >> it;
        int even = 0, odd = 0;
        bool con = false;
        vector<bool > m(120, false);
        for (int i = 0; i < a; ++i) {
            int temp;
            cin >> temp;
            if (temp % 2) {
                odd++;
            } else {
                even++;
            }

            m[temp] = true;
            if (m[temp-1] || m[temp+1]) con = true;
        }

        if (odd % 2 == 0 || con) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;

    }
    return 0;
}
