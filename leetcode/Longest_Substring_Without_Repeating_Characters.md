# Longest Substring Without Repeating Characters

## brute force
``` c++
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
