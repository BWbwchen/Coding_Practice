#define DEBUG
#include <bits/stdc++.h>
 
using namespace std;
 
int main ()
{
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif
    int queries;
    unsigned long long a, b, c;
    cin >> queries; 
 
    while (queries--) {
        cin >> a >> b >> c;
        if ((a%10 + b%10 + c%10)%2 == 0) cout << (a+b+c)/2 << endl;
        else cout << (a+b+c-1)/2 << endl;
    }
 
    return 0;
}