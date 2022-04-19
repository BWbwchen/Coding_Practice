class Solution {
public:
  bool isPalindrome(string s) {
    int left, right;
    left = 0;
    right = s.size() - 1;

    while (left < right && left < s.size() && right >= 0) {
      if (isalnum(s[left]) && isalnum(s[right])) {
        if (toupper(s[left]) != toupper(s[right])) {
          return false;
        } else {
          left++;
          right--;
        }
      } else {
        if (!isalnum(s[left])) {
          left++;
        }
        if (!isalnum(s[right])) {
          right--;
        }
      }
    }

    return true;
  }
};
