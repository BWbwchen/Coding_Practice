class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long total = 0;
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < skill.size(); ++i) {
            m[skill[i]].emplace(i); 
            total += skill[i];
        }
        total /= (skill.size()/2);
        
        long long ret = 0;
        unordered_map<int, bool> done;
        for (auto &mp : m) {
            done[mp.first] = false;
        }
        for (auto &mp : m) {
            auto v = mp.first;
            auto s = mp.second;
            
            if (done[v])
                continue;
            
            if (m.count(total - v) == 0)
                return -1;
            else if (m[total - v].size() != s.size())
                return -1;
            
            done[v] = true;
            done[total -v ] = true;
            
            if (total - v == v) {
                ret += s.size() * (v * (total - v)) / 2;    
            } else {
                ret += s.size() * (v * (total - v));
            }
        }       
       
        return ret;
        
    }
};
