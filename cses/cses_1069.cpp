//#define DEBUG
#define MAXN 2000000000
#define ll unsigned long long int
#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    
    string s;
    cin >> s;
 
    vector<int > v(s.length(), 1);
 
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            v[i] = v[i-1]+1;
        }
    }
    int _max = -MAXN;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > _max) _max = v[i];
    }
    cout << _max << endl;
 
 
 
    return 0;
}
