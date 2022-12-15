// #define DEBUG
#define MAXN 2000000000
#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> applicant(n);
    vector<ll> appartment(m);

    for (int i = 0; i < n; ++i)
        cin >> applicant[i];
    for (int i = 0; i < m; ++i)
        cin >> appartment[i];

    sort(applicant.begin(), applicant.end());
    sort(appartment.begin(), appartment.end());

    ll ans = 0;
    ll request = 0;
    ll resource = 0;
    while (request < n && resource < m) {
        if ((appartment[resource] - k <= applicant[request]) &&
            (applicant[request] <= appartment[resource] + k)) {
            ans++;
            resource++;
            request++;
        } else {
            if (appartment[resource] < applicant[request])
                resource++;
            else
                request++;
        }
    }

    cout << ans << endl;


    return 0;
}
