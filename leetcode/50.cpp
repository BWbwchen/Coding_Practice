class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        else if (n == -1)
            return 1 / x;
        else if (n == 1)
            return x;

        int sign = (n < 0 ? -1 : 1);

        double ans = 1.0;

        if (n < 0) {
            ans = myPow(x, n / 2);
            ans = ans * ans * (n % 2 ? 1 / x : 1.0);
        } else {
            ans = myPow(x, n / 2);
            ans = ans * ans * (n % 2 ? x : 1.0);
        }


        return ans;
    }
};

// Fast binary exponentiation
class Solution {
public:
    double myPow(double x, int n) {
        // x^n = x^(2^0) * x^(2^1) * x^(2^2) ...
        double ret = 1.0;
        double a = x;
        long long abs_n = abs(n);
        while (abs_n) {
            if (abs_n & 1)
                ret *= a;
            // x -> x^2
            // x^2 -> x^4
            a *= a;
            abs_n >>= 1;
        }
        if (n < 0)
            return 1.0 / ret;
        else
            return ret;
    }
};
