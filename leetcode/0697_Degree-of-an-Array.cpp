class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        // calculate max frequency
        // for each max frequency element, find the distance.
        // find the max distance of the max frequency element

        map<int, int> cnt;
        for (auto &n : nums) {
            cnt[n]++;
        }

        int max_freq = 0;
        for (auto &n : nums) {
            max_freq = max(max_freq, cnt[n]);
        }

        unordered_set<int> maxfreq;
        for (auto &np : cnt) {
            if (np.second == max_freq) {
                maxfreq.emplace(np.first);
            }
        }

        unordered_map<int, pair<int, int>> us_dis;
        for (int i = 0; i < nums.size(); ++i) {
            auto &n = nums[i];
            if (maxfreq.count(n)) {
                if (us_dis.count(n)) {
                    us_dis[n].second = i;
                } else {
                    us_dis[n] = make_pair(i, i);
                }
            }
        }

        int ret = 1000000;
        for (auto &np : us_dis) {
            ret = min(ret, np.second.second - np.second.first + 1);
        }

        return ret;
    }
};
