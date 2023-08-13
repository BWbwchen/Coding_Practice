// loop method
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n % 2 == 0 && n > 0) {
            n /= 2;
        }
        return n == 1;
    }
};

// bit operation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long k = n;
        return k && !(k & (k - 1));
    }
};
