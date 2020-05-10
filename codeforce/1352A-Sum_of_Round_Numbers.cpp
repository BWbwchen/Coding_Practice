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
        int n;
        cin >> n;
        int i = 1;
        int a = n;
        int count = 0;
        while (a) {
            if (a%10)
                count ++;
            a/=10;
        }
        cout << count << endl;
         
        while (n) {
            if (n%10) 
                cout << (n%10) * i << " ";
            i *= 10;
            n /= 10;
        }

        cout << endl;
    }

    return 0;
}
