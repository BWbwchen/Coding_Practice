class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        return n == (pow(4, (int)(log2(n)/log2(4)))); 
    }
};
