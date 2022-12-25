class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        for (int i = 0; i < forts.size(); ++i ) {
            if (forts[i] != 0) {
                // search
                int now = forts[i];
                int tmp = 0;
                for (int j = i + 1; j < forts.size(); ++j) {
                    if (forts[j] != 0) {
                        if (forts[j] + now == 0) {
                            tmp = j - i - 1; 
                        } else {
                            tmp = 0;
                        }
                        break;
                    } 
                }
                ans = max(ans, tmp);
            }
        }
            
        return ans;
        
    }
};
