#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int dist(string a, string b) {
    int ret = 0;
    for (int i = 0; i < a.size(); ++i) {
      ret += (a[i] == b[i]) ? 0 : 1;
    }
    return ret;
  }
  int minMutation(string start, string end, vector<string> &bank) {
    if (start == end)
      return 0;
    queue<pair<string, int>> q;
    q.push(make_pair(start, 0));
    unordered_set<string> ms;
    ms.emplace(start);

    while (!q.empty()) {
      auto ps = q.front();
      q.pop();

      for (auto &s : bank) {
        if (ms.find(s) == ms.end() && dist(s, ps.first) == 1) {
          if (s == end)
            return ps.second + 1;
          q.push(make_pair(s, ps.second + 1));
          ms.emplace(s);
        }
      }
    }
    return -1;
  }
};
