class Solution {
public:
    bool isValid(string s) {
        /*
         * ascii code:
         * ( == 40, ) == 41
         * { == 123, } == 125
         * [ == 91, ] == 93
         */
        stack<char > st;
        for (auto c : s) {
            if (c == ')' || c == ']' || c == '}') {
                if (!st.empty() && (st.top() == c-2 || st.top() == c-1)) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
