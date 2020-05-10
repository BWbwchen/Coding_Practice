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
        int total;
        cin >> total;
        vector<int > c(total, 0);
        for (int i = 0; i < total; ++i) {
            cin >> c[i];
        }
        bool end = false;
        int turn = 0, alice = 0, bob = 0;
        int low_limit = 0;
        while (!end) {
            // alice first
            int temp_eat = 0;
            for (int i = 0; i < c.size(); ++i) {
                temp_eat += c[i];
                if (temp_eat  > low_limit || i == c.size() - 1) {
                    c.erase(c.begin(), c.begin()+i+1);
                    low_limit = temp_eat;
                    alice += temp_eat;
                    temp_eat = 0;
                    turn++;
                    break;
                } 
            }
            if (c.size() == 0) {
                end = true;
            }

            // bob second
            temp_eat = 0;
            for (int i = c.size()-1; i >= 0; --i) {
                temp_eat += c[i];
                if (temp_eat > low_limit || i == 0) {
                    c.erase(c.begin()+i, c.end());
                    low_limit = temp_eat;
                    bob += temp_eat;
                    temp_eat = 0;
                    turn++;
                    break;
                }
            }
            if (c.size() == 0) {
                end = true;
            }
        }

        printf("%d %d %d\n", turn, alice, bob);

    }



    return 0;
}
