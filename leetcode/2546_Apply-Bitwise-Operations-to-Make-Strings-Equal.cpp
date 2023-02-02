class Solution {
public:
  bool makeStringsEqual(string s, string target) {
    /*
    0,0 -> 0, 0
    0,1 -> 1, 1 => 0->1
    1,0 -> 1, 1 => 0->1
    1,1 -> 1, 0 => 1->0
    */
    if (s.size() != target.size())
      return false;

    int zero = 0;
    int one = 0;

    for (auto &c : s) {
      if (c == '1')
        one++;
      else
        zero++;
    }

    int target_zero = 0;
    for (auto &c : target)
      if (c == '0')
        target_zero++;

    return (target == s) || (one != 0 && target_zero != target.size());
  }
};
