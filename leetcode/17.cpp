// faster than 100% solution
class Solution {
public:
    vector<string > temp = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        return _recursive(digits);
    }
    
    vector<string> _recursive(string digits) {
        vector<string > res;
        if (digits.size() == 0) {
            return {""};
        }
        int head = digits[0] - '0';
        vector<string > t = _recursive(tail(digits));
        for (auto c : temp[head]) {
            for (int i = 0; i < t.size(); ++i) {
                res.push_back(c+t[i]);
            }
        }
        return res;
    }
    
    
    string tail(string a) {
        if (a.size() == 0) {
            return "";
        } else {
            return a.substr(1);
        }
    }
};
