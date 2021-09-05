// brute force TLE
class Solution {
public:
    const int MAXN = 1000000;
    int largestRectangleArea(vector<int>& heights) {
        int ans = -1000;
        for (int amount = 0; amount < heights.size(); ++amount) {
            for (int index = 0; index + amount < heights.size(); ++index) {
                int width = amount + 1;
                int minHeight = MAXN;
                for (int offset = 0; offset <= amount; ++offset) {
                    minHeight = min(minHeight, heights[index+offset]); 
                }
                ans = max(ans, minHeight*width);
            }
        }
        return ans;
    }
};
// O(n)
// The possible width of a rectangle is 1 ~ n. So we can use an O(n) algorithm
// to solve this problem.
// We first try to maximize the width under the increase of the next bar we met,
// we called those bars "candidate bars". 
// When we met a bar that is lower than we most recently met, 
// we need to adjust the candidate bars under the condition of "increasing". 
// I will start to calculate the maximum area we can make base on the candidate bars' condition.
class Solution {
public:
    const int MAXN = 1000000;
    stack<pair<int, int>> candicate;
    
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> ns;
        candicate = ns;
        
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
