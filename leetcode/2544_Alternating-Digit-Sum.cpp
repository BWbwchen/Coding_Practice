class Solution {
public:
  int alternateDigitSum(int n) {
    int ans = 0;
    int digit = 0;
    while (n) {
      digit++;
      if (digit % 2) {
        ans += n % 10;
      } else {
        ans -= n % 10;
      }
      n /= 10;
    }
    if (digit % 2 == 0) {
      ans = -ans;
    }
    return ans;
  }
};
