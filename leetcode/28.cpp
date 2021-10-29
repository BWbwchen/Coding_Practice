class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            int id = find(haystack, needle, i);
            if (id != -1) {
                return id;
            }
        }
        return -1;
    }
    
    int find(string haystack, string needle, int id) {
        for (int i = 0; i < needle.size(); ++i) {
            if (haystack[id+i] != needle[i]) {
                return -1;
            }
        }
        return id;
    }
};
