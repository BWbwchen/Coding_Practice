class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        
        long ans = 0;
        while(dvd >= dvs) {
            long tmp = dvs;
            long count = 1;
            while (tmp << 1 <= dvd) {
                count <<= 1; 
                tmp <<= 1;
            }
            dvd -= tmp;
            ans += count;
        }
        return sign * ans;
    }
};
