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
        //printf("new query\n");
 
        int ans = MAXN;
        // for each t-string
        for (int t_offset = 0; t_offset < 3; ++t_offset) {
            // RGB GBR BRG

            // base case
            int count = 0;
            for (int i = 0; i < sub_length; ++i) {
                if (s[i] != t[(t_offset+i)%3])
                    count++;
            }
            ans = min(count, ans);

            for (int i = 1; i <= length - sub_length; ++i) {
                if (s[i-1]!=t[(t_offset+i-1)%3]) count--;
                if (s[i+sub_length-1]!=t[(t_offset+i+sub_length-1)%3]) count++;
                ans = min(count, ans);
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}
