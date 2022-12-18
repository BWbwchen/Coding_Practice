class Solution {
public:
    vector<int> prime(int n) {
        vector<int> ret;
        for (int i = 2; i <= (int)n; ++i) {
            while(n % i == 0) {
                ret.emplace_back(i);
                n /= i;
            }
        }
        if (ret.size() == 0)
            ret.emplace_back(n);
        return ret;
    }
    int smallestValue(int n) {
        int my_n = n;
        while(true) {
            cout << my_n << endl;
            vector<int> pf = prime(my_n);
            if (pf.size() == 1)
                return my_n;
            int nn = 0;
            for (auto &a : pf) {
                nn += a;
            }
            if (my_n == nn) {
                return nn;
            }
            my_n = nn;
        }
        return my_n;
    }
};
