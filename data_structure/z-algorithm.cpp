#define DEBUG
#define MAXN 2000000000
#include <bits/stdc++.h>
using namespace std;

vector<int> getAns(string pattern, vector<int> v) {
  vector<int> ans;
  int n = pattern.length();
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == n) {
      ans.push_back(i);
    }
  }
  return ans;
}

void printer(vector<int> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

// -------------------------------------------------------------------------
// //

// O(m + n)
vector<int> StringMatching(string pattern, string str) {
  string s = pattern + "$" + str;
  vector<int> z(s.length());

  int left = 0;
  int right = 0;

  z[0] = 0;
  for (int i = 1; i < s.length(); ++i) {
    if (i > right) {
      // normal stage
      left = right = i;
      while (right < s.length() && s[right] == s[right - left])
        right++;
      z[i] = right - left;
      right--;
    } else {
      // smart stage
      int new_i = i - left;
      // whether it will start a new pattern matching.
      if (z[new_i] < right - i + 1) {
        z[i] = z[new_i];
      } else {
        // redo the pattern matching with noremal method
        left = new_i;
        while (right < s.length() && s[right] == s[right - left])
          right++;
        z[i] = right - left;
        right--;
      }
    }
  }

  vector<int> ans(z.begin() + pattern.length() + 1, z.end());
  return getAns(pattern, ans);
  // return ans;
}

// O(n^2) Z-algorithm
vector<int> StringMatchingBruteForce(string pattern, string str) {
  string s = pattern + "$" + str;
  vector<int> z(s.length());
  for (int i = 0; i < s.length(); ++i) {
    int count = 0;
    while ((i + count) < s.length() && s[i + count] == s[count])
      count++;
    z[i] = count;
  }
  vector<int> ans(z.begin() + pattern.length() + 1, z.end());
  return getAns(pattern, ans);
  // return ans;
}

int main() {
#ifdef DEBUG
  freopen("in.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<string, string>> testSet = {{"abc", "xabcabzabc"},
                                          {"abc", "abcabcabcabcabc"}};

  int total = testSet.size();
  int pass = 0;
  for (auto test : testSet) {
    string pattern = test.first;
    string str = test.second;
    // printer(StringMatchingBruteForce(pattern, str));
    // printer(StringMatching(pattern, str));
    vector<int> z_algo_ans = StringMatching(pattern, str);
    vector<int> brute_force_ans = StringMatchingBruteForce(pattern, str);

    if (z_algo_ans.size() != brute_force_ans.size()) {
      cout << "Length Error" << endl;
      continue;
    }

    bool p = true;
    for (int i = 0; i < z_algo_ans.size(); ++i) {
      if (z_algo_ans[i] != brute_force_ans[i]) {
        cout << "Content Error" << endl;
        p = false;
      }
    }

    if (p) {
      pass++;
    }
  }

  printf("%d / %d pass\n", pass, total);
  return 0;
}
