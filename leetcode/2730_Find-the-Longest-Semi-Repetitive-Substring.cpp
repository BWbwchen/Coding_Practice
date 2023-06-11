class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool find_double = false;
            int count = 1;
            // unordered_set<char> us;
            char prev = s[i];
            for (int j = i + 1; j < s.size(); ++j) {
                if (prev == s[j]) {
                    if (find_double) {
                        break;
                    } else {
                        find_double = true;
                    }
                }
                count++;
                // us.emplace(s[j]);
                prev = s[j];
            }
            answer = max(answer, count);
        }
        return answer;
    }
};
