#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> ans;
  vector<vector<bool>> isPar;
  vector<string> temp;
  string ss;
  void palindrome(string s) {
    isPar =
        vector<vector<bool>>(s.size() + 1, vector<bool>(s.size() + 1, false));
    for (int i = 0; i < s.size(); ++i)
      isPar[i + 1][i + 1] = true;

    for (int i = 1; i < s.size(); ++i)
      isPar[i][i + 1] = s[i - 1] == s[i];

    for (int i = s.size(); i >= 1; --i) {
      for (int j = s.size(); j >= i + 2; --j) {
        if (s[i - 1] == s[j - 1])
          isPar[i][j] = isPar[i + 1][j - 1];
      }
    }
  }

  void partition(int start, int end) {
    if (start == end) {
      ans.push_back(temp);
      return;
    } else if (start > end) {
      temp = vector<string>();
      return;
    }

    for (int j = start; j < end; ++j) {
      if (isPar[start + 1][j + 1]) {
        temp.push_back(ss.substr(start, j - start + 1));
        partition(j + 1, end);
        temp.pop_back();
      }
    }
    return;
  }
  vector<vector<string>> partition(string s) {
    ss = s;
    palindrome(s);
    partition(0, s.size());
    return ans;
  }
};
