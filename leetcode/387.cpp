class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        
        for (int i = 0; i < 26; ++i) {
            mp[i+'a'] = -1; 
        }
        
        for (int i = 0; i < s.length(); ++i) {
            mp[s[i]] = i;
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if (mp[s[i]] == i) {
                return i;        
            } else {
                mp[s[i]] = i;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i] - 'a']++; 
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (mp[s[i] - 'a'] == 1) {
                return i;
            } 
        }
        
        return -1;
    }
};
