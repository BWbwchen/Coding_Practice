class Solution {
public:
    using ull = unsigned long long int;
    ull MAXN = 1000000007;
    vector<string> tokenize(string const &str) {
        vector<string> out;
        // construct a stream from the string
        std::stringstream ss(str);

        std::string s;
        while (std::getline(ss, s, ' ')) {
            out.push_back(s);
        }
        return out;
    }
    int countAnagrams(string s) {
        auto vs = tokenize(s);

        int n = s.size();
        vector<ull> f(n + 1, 1), invi(n + 1, 1), invf(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i - 1] * i % MAXN;
            invi[i] = MAXN - MAXN / i * invi[MAXN % i] % MAXN;
            invf[i] = invf[i - 1] * invi[i] % MAXN;
        }
        unsigned long long int ans = 1;
        for (auto &ss : vs) {
            unordered_map<char, unsigned long long int> us;
            unsigned long long int tmp = f[ss.size()];
            for (auto &c : ss) {
                if (us.count(c) > 0) {
                    us[c]++;
                } else {
                    us[c] = 1;
                }
            }

            for (auto &mm : us) {
                auto &v = mm.second;
                tmp *= invf[v];
                tmp %= MAXN;
            }
            ans *= tmp % MAXN;
            ans %= MAXN;
        }
        return ans;
    }
};
