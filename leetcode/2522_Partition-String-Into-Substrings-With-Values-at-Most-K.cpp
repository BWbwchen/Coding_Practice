class Solution {
public:
    int minimumPartition(string s, int k) {
        unsigned long long int left = 0, right = 0;

        unsigned long long int ret = 0;
        while (right < s.size()) {
            unsigned long long int nn =
                strtoul(s.substr(left, right - left + 1).c_str(), nullptr, 0);
            if (nn <= k) {
                right++;
            } else {
                if (right == left)
                    return -1;
                cout << strtoul(s.substr(left, right - left).c_str(), nullptr,
                                0)
                     << endl;
                ret++;
                left = right;
            }
        }
        if (strtoul(s.substr(left, right - left).c_str(), nullptr, 0) <= k)
            ret++;

        return ret == 0 ? -1 : ret;
    }
};
