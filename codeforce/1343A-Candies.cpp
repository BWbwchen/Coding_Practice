#define DEBUG
#define MAXN 10000000
#include <bits/stdc++.h>
using namespace std;


long long int my_pow (int times) {
    long long int sum = 1;
    for (int i = 0; i < times; ++i) {
        sum *= 2;
    }
    return sum;
}

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long int n, sum;
        cin >> n;
        for (int i = 2; i < 30; ++i) {
            sum = my_pow(i);
            sum -= 1;
            if (n % sum == 0) {
                cout << n / sum << endl;
                break;
            }
        }
        
    }

    return 0;
}
