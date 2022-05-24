#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    bool inword = false;
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        if (inword) {
          ans++;
        } else {
          ans = 1;
          inword = true;
        }
      } else {
        inword = false;
      }
    }
    return ans;
  }
};
