#include <vector>
#define DEBUG
#define MAXN 10000000
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
        vector<int > v(n+1, 0);

        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            ++v[t];
        }

        int ans = 0;
        for (int i = 1; i < n+1; ++i) {
            ans += (v[i] / i) ;
            v[i] %= i;
        }

        
        int temp = 0;
        for (int i = 1; i < n+1; ++i) {
            if (v[i]) {
                temp += v[i];
                if (temp / i) {
                    ans += (temp / i);
                    temp %= i;
                }
            }
        }
        
        cout << ans << endl;

    }

    return 0;
}
