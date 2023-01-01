class Solution {
public:
    int countDigits(int num) {
        int nn = num;
        int ret = 0;
        while (nn) {
            int dd = nn % 10;
            if (num % dd == 0)
                ret++;
            nn /= 10;
        }
        return ret;
    }
};
