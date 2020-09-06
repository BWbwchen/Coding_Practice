class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string > res;
        add(res, "", n, 0);
        return res;
    }
    void add (vector<string > &res, string answer, 
              int left_parenthesis, int right_parenthesis) {
        if (left_parenthesis == 0 && right_parenthesis == 0) {
            res.push_back(answer);
            return;
        }
        
        if (left_parenthesis > 0) 
            add(res, answer+"(", left_parenthesis-1, right_parenthesis+1);
        if (right_parenthesis > 0)
            add(res, answer+")", left_parenthesis, right_parenthesis-1);
    }
};
