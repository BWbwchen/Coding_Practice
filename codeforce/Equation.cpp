// https://codeforces.com/contest/1269/problem/A
#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main () {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif 

    // the base case is 1
    // which is 8 and 9 or 14 and 15
    // so what about 2 ?
    // 8*2 and 9*2 !!
    int n;
    cin >> n;
    cout << 8*n << " " << 9*n << endl;
    return 0;
}
