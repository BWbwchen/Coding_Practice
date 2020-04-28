#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    /*
     * 1. if A can see B, then B can see A
     *    So we count A's answer and *2 will get correct answer
     *    So we count the left side of each building
     * 2. Notice that 
     *      (1) if now_building < left => than now_building can only see 1(left side)
     *      (2) if now_building = left => than now_building can see the all same high building and the next higher building 
     *      (3) if now_building > left => than now_building can see left side until it got the building higher than itself
     */
    
    long long int ans = 0;
    stack<int> mono, num_equal;
    mono.push(a[0]);
    num_equal.push(1);
    for (int i = 1; i < n; ++i) {
        while (!mono.empty() && a[i] > mono.top()) {
            ans += num_equal.top();
            mono.pop();
            num_equal.pop();
        }

        if (!mono.empty() && a[i] == mono.top()) {
            ans += num_equal.top();  
            num_equal.top()++;
        } else {
            // no ans++ here
            // because there could have mono == empty case
            mono.push(a[i]);
            num_equal.push(1);
        }
        // why ??
        // for normal case a[i] < mono.top()
        if (mono.size() > 1) ans ++;

    }
    cout << 2 * ans << endl;

    return 0;
}
