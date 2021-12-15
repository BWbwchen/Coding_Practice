class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        else if (n == -1) return 1/x;
        else if (n == 1) return x;
        
        int sign = (n < 0 ? -1 : 1);
        
        double ans = 1.0;
        
        if (n < 0) {
            ans = myPow(x, n/2);
            ans = ans * ans * (n % 2 ? 1/x:1.0);
        } else {
            ans = myPow(x, n/2);
            ans = ans * ans * (n % 2 ? x:1.0);
        }
        
        
        return ans;
    }
};
