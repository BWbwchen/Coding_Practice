class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string n_1 = countAndSay(n-1);
        string ans = "";
        int i = 0;
        int count = 1;
        while (i < n_1.size()) {
            if (i == n_1.size()) {
                ans += to_string(count) + n_1[i];
                break;
            }
            if (n_1[i] == n_1[i+1]) count ++;
            else {
                ans += to_string(count) + n_1[i]; 
                count = 1;
            }
            i++;
        }
        return ans;        
    }
};
