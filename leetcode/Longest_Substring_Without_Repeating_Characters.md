# Longest Substring Without Repeating Characters

## brute force
```cpp=
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force
        int answer = 0;
        for (int i = 0; i < s.length(); ++i) {
            set <char> visited;
            for (int j = i; j < s.length(); ++j) {
                if (visited.count(s[j]) == 0) visited.insert(s[j]);
                else {
                    break;
                }
            }
            int temp = visited.size();
            if (temp > answer) answer = temp;
        }
        return answer;
    }
};
```

## sliding window
```cpp=
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force
        if (s.size() <= 1) return s.size();
        int ans = 0;
        int left = 0, right = 0;
        vector<int> index(256, -1);
        while (right < s.size() && left < s.size()) {
            if (index[s[right]] == -1) {
                index[s[right]] = right;
                ans = max(ans, right-left+1);
                right++;
            }else {
                index[s[left++]] = -1;
            }
        }
        return ans;
    }
};
```

## sliding window and remove more duplicate step
```cpp=
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force
        if (s.size() <= 1) return s.size();
        int ans = 0;
        int left = 0, right = 0;
        vector<int> index(256, -1);
        while (right < s.size()) {
            if (index[s[right]] != -1 && index[s[right]] >= left) {
                left = index[s[right]]+1;
            }
            index[s[right]] = right;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};
```
