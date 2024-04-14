class Solution {
public:
    const int MAXN = 1000000;
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));        
        
        for (int col = 0; col < matrix[0].size(); ++col) {
            for (int row = 0; row < matrix.size(); ++row) {
                if (matrix[row][col] == '0') {
                    dp[row][col] = 0;
                } else {
                    if (row-1 < 0) dp[row][col] = 1;
                    else dp[row][col] = dp[row-1][col] + 1;
                }
            }
        }
        
        int ans = -MAXN;
        for (int row = 0; row < matrix.size(); ++row) {
            ans = max(ans, largestRectangleArea(dp[row]));         
        }
        
        return ans;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> candicate;
        
        heights.push_back(0);
        
        int ans = 0;
        
        candicate.push(make_pair(-1, 0)); 
        
        for (int i = 0; i < heights.size(); ++i) {
            while(!candicate.empty() && candicate.top().second > heights[i]) {
                auto top = candicate.top();
                candicate.pop();
                //cout << top.first << " " << top.second << endl; 

                ans = max(ans, (i - candicate.top().first - 1) * top.second);
                //cout << i-1 << " back to " << candicate.top().first << " and the value is : " << (i - candicate.top().first - 1) * top.second << endl;
            }
            candicate.push(make_pair(i, heights[i]));
        }
        
        heights.pop_back();
        
        return ans;
    }
};
