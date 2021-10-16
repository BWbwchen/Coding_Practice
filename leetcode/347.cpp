// brute force method
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        
        for (auto n : nums) {
            if (m.find(n) != m.end()) {
                m[n]++;
            } else {
                m[n] = 1;
            }
        }
        
        vector<pair<int, int>> v; 
        for (const auto& [key, value]: m) {
            v.push_back(make_pair(value, key));
        }
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        vector<int> ret(k, 0);
        
        for (int i = 0; i < k; ++i) {
            ret[i] = v[i].second;
        }
        
        
        return ret; 
    }
};
