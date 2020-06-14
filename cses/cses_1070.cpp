//#define DEBUG
#define MAXN 2000000000
#define ll unsigned long long int
#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    
    int n;
    cin >> n;
 
    // 5
    // 1 4 2 5 3
    // 3 
    // 1 3 2 
    // 4
    // 1 3 2 4
    // 6
    // 1 4 2 5 3 6
    // 7
    // 1 5 2 6 3 7 4
    // 1 2 3 ... (n+1)/2
    // (n+1)/2+1 ... 
    if (n == 1) cout << 1 << " ";
    else if (n == 2 || n == 3) cout << "NO SOLUTION" << endl;
    else if (n == 4) {
        cout << "2 4 1 3" << endl;
    }
    else {
        vector<int > v(n, 0);
        int k = 0;
        for (int i = 0; i < (n+1)/2; ++i, ++k) {
            v[2*k] = i+1;
        }
        k = 0;
        for (int i = (n+1)/2 + 1; i <= n; ++i, ++k) {
            v[2*k+1] = i;
        }
        for (auto a : v) cout << a << " ";
        cout << endl;
    }
 
 
    return 0;
}
