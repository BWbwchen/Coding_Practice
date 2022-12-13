// recursive method
class Solution {
public:
    int idx;
    bool is_operator(string &s) {
        return s == "*" || s == "+" || s == "-" || s == "/";
    }
    int evalRPN(vector<string> &tokens) {
        idx = tokens.size() - 1;
        return eval(tokens);
    }
    int eval(vector<string> &tokens) {
        if (idx < 0)
            return 0;

        if (is_operator(tokens[idx])) {
            if (tokens[idx] == "+") {
                idx--;
                int l = eval(tokens);
                idx--;
                int r = eval(tokens);
                return l + r;
            } else if (tokens[idx] == "-") {
                idx--;
                int l = eval(tokens);
                idx--;
                int r = eval(tokens);
                return r - l;
            } else if (tokens[idx] == "*") {
                idx--;
                long long int l = eval(tokens);
                idx--;
                long long int r = eval(tokens);
                return l * r;
            } else {
                // divide
                idx--;
                int l = eval(tokens);
                idx--;
                int r = eval(tokens);
                return ((double) r / (double) l);
            }
        } else {
            return stoi(tokens[idx]);
        }
        return 0;
    }
};

// stack method
class Solution {
public:
    bool is_operator(string &s) {
        return s == "*" || s == "+" || s == "-" || s == "/";
    }
    int evalRPN(vector<string> &tokens) {
        stack<long long> st;
        for (auto &s : tokens) {
            if (!is_operator(s)) {
                st.emplace(stoi(s));
            } else {
                if (s == "+") {
                    long long r = st.top();
                    st.pop();
                    long long l = st.top();
                    st.pop();
                    st.emplace(l + r);
                } else if (s == "-") {
                    long long r = st.top();
                    st.pop();
                    long long l = st.top();
                    st.pop();
                    st.emplace(l - r);
                } else if (s == "*") {
                    long long r = st.top();
                    st.pop();
                    long long l = st.top();
                    st.pop();
                    st.emplace(l * r);
                } else {
                    // divide
                    long long r = st.top();
                    st.pop();
                    long long l = st.top();
                    st.pop();
                    st.emplace((double) l / (double) r);
                }
            }
        }
        return st.top();
    }
};
