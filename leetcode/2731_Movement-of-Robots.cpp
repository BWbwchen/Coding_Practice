class Solution {
    using ll = long long;

public:
    int sumDistance(vector<int> &nums, string s, int d) {
        // since the collision doesn't matter.
        // think about if collision, just bypass it, and it has no difference
        // between collision and bypass.
        vector<ll> pos(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (s[i] == 'R')
                pos[i] += d;
            else
                pos[i] -= d;
        }

        sort(pos.begin(), pos.end());

        ll accu = 0;
        ll ans = 0;
        ll mod = 1000000007;
        for (int i = 0; i < pos.size(); ++i) {
            // calculate the answer of :
            // dis(0, i) + dis(1, i) + ... + dis(i-1, i) + dis(i, i)
            // it can be rewritten as:
            // (pos[i] - pos[0]) + (pos[i] - pos[1]) + ... (pos[i] - pos[i])
            // rearrange:
            // (i + 1) * pos[i] - (pos[0] + pos[1] + ... pos[i])
            accu += pos[i];
            ans += (i + 1) * pos[i] - accu;
            ans %= mod;
        }
        return ans;
    }
};
