class Solution {
public:
    bool isprime(int n) {
        int pc = 2;
        while (n > 1) {
            // cout << n << "/" << pc << endl;
            if (n % pc == 0) {
                return false;
            }
            pc++;
            if (pc == n) {
                // cout << n << " is a prime!" << endl;
                return true;
            }
        }
        return false;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);
        prime[0] = false;
        prime[1] = false;
        int pc = 2;
        int n = right;
        for (int i = 2; i <= right; i++)
            if (prime[i])
                for (int j = i + i; j <= right; j += i)
                    prime[j] = false;
        vector<int> pp;
        for (int i = left; i <= right; ++i) {
            if (prime[i])
                pp.emplace_back(i);
        }
        if (pp.size() < 2)
            return {-1, -1};

        int ll = pp[0], rr = pp[1], delta = pp[1] - pp[0];
        for (int i = 2; i < pp.size(); ++i) {
            if (pp[i] - pp[i - 1] < delta) {
                ll = pp[i - 1];
                rr = pp[i];
                delta = rr - ll;
            }
        }

        return {ll, rr};
    }
};
