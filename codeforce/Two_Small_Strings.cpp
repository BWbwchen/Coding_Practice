// https://codeforces.com/contest/1213/problem/E
// idea : https://github.com/Just-A-Visitor/Coding/blob/master/Codeforces%20Contests/CF%20Round%20582/Images/ReadMe.md
#define DEBUG
#define MAXN 1e9+10
#include <bits/stdc++.h>
 

using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    string sub = "abc";
    string ans;
    bool flag = false;
    
    
    do {
        string test;
        for (int i = 0; i < n; ++i) test+=sub;
        if (test.find(a) == string::npos && test.find(b) == string::npos) {
            flag = true;
            ans = test;
            break;
        } else {
            test = string(n, sub[0])+string(n, sub[1])+string(n, sub[2]);
            if (test.find(a) == string::npos && test.find(b) == string::npos) {
                flag = true; 
                ans = test;
                break;
            }
        }

    } while (next_permutation(sub.begin(), sub.end()));

    if (flag) {
        cout << "YES\n";
        cout << ans << endl;
    } else cout << "NO\n";

    return 0;
}


