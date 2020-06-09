//#define DEBUG
#define MAXN 2000000000
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t ; 
    cin >> t ;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<bool >> v(n, vector<bool >(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char a;
                cin >> a;
                if (a=='1') v[i][j] = true;
            }
        }

        bool flag = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // right and down 
                if (j + 1 < n && i + 1 < n && v[i][j]){
                    flag &= (v[i][j+1] | v[i+1][j]);
                }
            }
        }
        //cout << n << endl;

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
