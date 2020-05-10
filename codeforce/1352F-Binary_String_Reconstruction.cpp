#define DEBUG
#define MAXN 10000000
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string ans ;
        string ans_n0, ans_n2;


        // deal n1 first and add front n0 and add back n2
        if (n1) {
            for (int i = 0; i < n1+1 ; ++i) {
                if (i%2 == 0) 
                    ans+='1';
                else 
                    ans+='0';
            }
            ans.insert(1, string(n0, '0'));
            ans.insert(0, string(n2, '1'));
            cout << ans << endl;
        } else {
            if (n0) 
                cout << string(n0+1, '0') << endl;
            else 
                cout << string(n2+1, '1') << endl;
        }
        
        //cout << ans_n2+"*"+ans+"*"+ans_n0 << endl;
        //cout << ans << endl;
    }


    return 0;
}
