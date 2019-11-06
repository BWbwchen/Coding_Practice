// DP VERSION
#define DEBUG
#define MAXN 1000000
#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif
    
    int query;
    cin >> query;
 
    const string t = "RGB";
 
    while (query--) {
        int length, sub_length;
        string s;
        cin >> length >> sub_length >> s;
 
        int ans = MAXN;
        int dp[3][length];
        // the i+1-th is denote the different number of character of the previous i character
        // cause if use i-th will need to write the base case
        dp[0][0] = dp[1][0] = dp[2][0] = 0;
        for (int t_offset = 0; t_offset < 3; ++t_offset) {
            // RGB GBR BRG
            // construct dp array
            for (int i = 1; i <= length; ++i) {
                if (s[i-1]!=t[(t_offset+i-1)%3])
                    dp[t_offset][i] = dp[t_offset][i-1] + 1;
                else 
                    dp[t_offset][i] = dp[t_offset][i-1];
            }
            for (int i = sub_length; i <= length; ++i) {
                ans = min(ans, dp[t_offset][i]-dp[t_offset][i-sub_length]);
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}
