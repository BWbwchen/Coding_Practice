class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0) {
            int aa = a & 1;
            int bb = b & 1;
            int cc = c & 1;

            if ((aa | bb) == cc) {
                // do nothing
            } else {
                if (cc == 0) {
                    flips += (aa == 0 ? 0 : 1) + (bb == 0 ? 0 : 1);
                } else {
                    flips++;
                }
            }


            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};
