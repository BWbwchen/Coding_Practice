class Solution {
public:
    bool isFascinating(int n) {
        vector<int> v(10, 0);
        long long on = n;
        long long o2 = 2 * n;
        long long o3 = 3 * n;

        while (on) {
            v[on % 10]++;
            on /= 10;
        }
        while (o2) {
            v[o2 % 10]++;
            o2 /= 10;
        }
        while (o3) {
            v[o3 % 10]++;
            o3 /= 10;
        }
        if (v[0] != 0) {
            return false;
        }
        for (int i = 1; i <= 9; ++i) {
            if (v[i] == 0 || v[i] != 1)
                return false;
        }
        return true;
    }
};
