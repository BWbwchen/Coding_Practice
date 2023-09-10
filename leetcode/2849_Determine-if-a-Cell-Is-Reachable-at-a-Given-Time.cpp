class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        long long x = abs(fx - sx);
        long long y = abs(fy - sy);

        if (x == 0 && y == 0) {
            return t != 1;
        }

        // (1, 1)
        long long ret = min(x, y);
        x -= ret;
        y -= ret;

        if (ret + x + y <= t) {
            return true;
        } else {
            return false;
        }

        // return hpwl <= 2 * (long long) t;
    }
};
