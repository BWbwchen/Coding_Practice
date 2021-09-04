// Use two pointer
// First match all the substring t.
// Second, try to minimize the length
class Solution {
public:
    const int NOTHING = 1; 
    const int COLLECT = 2; 
    const int MAXN = 10000000; 
    
    string minWindow(string s, string t) {
        vector<int> charMap(129, 0);
        vector<int> findMap(129, 0);
        int state = NOTHING;
        
        int temp_start = 0;
        int temp_len = 0;
        int counter = t.size();
        
        int ans_start = 0;
        int ans_len = MAXN;
        
        for (int i = 0; i < t.size(); ++i)  charMap[(int)t[i]]++;
        findMap = charMap;
        
        for (int i = 0; i < s.size(); ++i) {
            // add this word 
            findMap[(int)s[i]]--;
            if (findMap[(int)s[i]] >= 0) {
                counter--;
            }
            
            temp_len++;
            
            if (counter == 0) {
                // try to release some unnecessary beginning
                while (counter == 0) {
                    if (temp_len < ans_len) {
                        ans_start = temp_start; 
                        ans_len = temp_len; 
                    }
                    temp_start ++;
                    temp_len --;
                    if (findMap[s[temp_start-1]]++ == 0) counter++;
                }
            }
        }
        
        if (ans_len == MAXN) return "";
        else return s.substr(ans_start, ans_len);
    }
};
