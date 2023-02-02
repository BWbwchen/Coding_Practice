// #define DEBUG
#define MAXN 2000000000
#define llu unsigned long long
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> a;
vector<int> segtree;

void build(int i, int l, int r, bool OR) {
  if (l == r) {
    segtree[i] = a[l];
    return;
  }

  int m = (l + r) >> 1;
  build(2 * i, l, m, !OR);
  build(2 * i + 1, m + 1, r, !OR);

  if (OR)
    segtree[i] = segtree[2 * i] | segtree[2 * i + 1];
  else
    segtree[i] = segtree[2 * i] ^ segtree[2 * i + 1];
}

void update(int i, int qi, int q, int l, int r, bool OR) {
  if (l == r) {
    a[l] = q;
    segtree[i] = q;
    return;
  }

  int m = (l + r) >> 1;

  if (qi <= m)
    update(2 * i, qi, q, l, m, !OR);
  else
    update(2 * i + 1, qi, q, m + 1, r, !OR);

  if (OR)
    segtree[i] = segtree[2 * i] | segtree[2 * i + 1];
  else
    segtree[i] = segtree[2 * i] ^ segtree[2 * i + 1];
}

int main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int length, num_query;
  cin >> length >> num_query;

  a.resize(1 << length);
  segtree.resize(1 << (length + 1));

  for (auto &n : a)
    cin >> n;

  vector<pair<int, int>> query(num_query);
  for (auto &p : query)
    cin >> p.first >> p.second;

  build(1, 0, a.size() - 1, length % 2);

  for (auto &q : query) {
    update(1, q.first - 1, q.second, 0, a.size() - 1, length % 2);
    cout << segtree[1] << endl;
  }

  return 0;
}
