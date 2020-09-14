class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        else if (n==2) return 2;
        vector<int > ans(n+1, 0);
        ans[0] = 1;
        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                ans[i] += ans[j-1] * ans[i-j];
            }
        }
        return ans[n];
    }
};
