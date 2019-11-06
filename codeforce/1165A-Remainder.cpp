#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main ()
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    string s;
    int len, x, y, count = 0;

    cin >> len >> x >> y >> s;

    for (int i = 0; i < x; ++i) {
        if (i == y) {
            if (s[len-1-i] == '0') {
                s[len-1-i] = s[len-1-i] - 1;
                count++;
            }
        } else {
            if (s[len-1-i] == '1') {
                s[len-1-i] = s[len-1-i] + 1;
                count++;
            }
        }
    }
    cout << count << endl;


    return 0;
}
