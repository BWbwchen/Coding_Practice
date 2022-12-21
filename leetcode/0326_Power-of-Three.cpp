class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        return (int)pow(3, (int)(log2(n)/log2(3))) == n;
    }
};
