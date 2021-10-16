class Solution {
public:
    int id = 0;
    string decodeString(string s) {
        string ret = "";
        int duplicateNum = 0;
        for (; id < s.size(); ++id) {
            char cur = s[id];
            if (isdigit(cur)) {
                duplicateNum = 10 * duplicateNum + (cur - '0');
            } else if (cur == '[') {
                id ++;
                string substring = decodeString(s);
                for (int i = 0; i < duplicateNum; ++i) ret += substring;
                duplicateNum = 0;
            } else if (cur == ']') {
                return ret; 
            } else {
                ret += s[id]; 
            }
        }
        return ret;
    }
};
