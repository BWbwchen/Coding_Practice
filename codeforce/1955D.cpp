#define MAXN 2000000000
#define llu unsigned long long
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
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
  while(t--) {
    int ans = 0;
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n, 0);
    vector<int> b(m, 0);
    unordered_map<int, int> um_a;
    unordered_map<int, int> um_b;

    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < m; ++i)
      cin >> b[i];
      
    for (auto &v : b)
      um_b[v]++;

    um_a.clear();
    int valid = 0;
    for (int start = 0; start + m- 1 < n; ++start) {
        if (start == 0) {
            for (int j = 0; j < m; ++j) {
                um_a[a[start + j]]++;
            } 
            for (auto &bp : um_b) {
                valid += min(um_a[bp.first], bp.second);
            }
        } else {
            int left = a[start-1];
            int right = a[start+m-1];
            valid -= min(um_a[left], um_b[left]);
            valid -= min(um_a[right], um_b[right]);

            // remove left boundary
            um_a[left]--;

            // add right boundary
            um_a[right]++;

            valid += min(um_a[left], um_b[left]);
            valid += min(um_a[right], um_b[right]);
        }

        if (valid >= k)
            ans++;
    }

    cout << ans << endl;
  }

  
  return 0;
}
