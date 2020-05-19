#include <algorithm>
#define DEBUG
#define MAXN 10000000
#define LLMIN -922337203685477580
#define ll unsigned long long int 
#define PI 3.14159265
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    long double a, b, h, m;
    cin >> a >> b >> h >> m;
    const long double pi = std::acos(-1);
    cout.precision(17);

    long double radius = (((30*h) - 5.5*m)* pi / 180.0);
    long double temp = (a*a) + (b*b) - 2*a*b*cosl(radius);
    long double ans = sqrt(temp);

    cout << ans << endl;




    return 0;
}
