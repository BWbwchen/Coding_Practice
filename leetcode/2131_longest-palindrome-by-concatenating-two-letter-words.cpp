#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    int answer = 0;
    unordered_map<string, int> mp;
    bool center = false;
    for (auto &w : words)
      mp[w]++;

    for (auto &p : mp) {
      auto w = p.first;
      auto count = p.second;
      if (w[0] == w[1]) {
        if (count % 2 == 0) {
          answer += count;
        } else {
          answer += count - 1;
          center = true;
        }
      } else {
        if (w[0] < w[1] && mp.find({w[1], w[0]}) != mp.end()) {
          int rever_count = mp[{w[1], w[0]}];
          answer += 2 * min(rever_count, count);
        }
      }
    }

    if (center)
      answer++;

    return 2 * answer;
  }
};
