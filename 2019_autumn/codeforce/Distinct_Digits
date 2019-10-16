#define DEBUG
#define MAXN 1000000
#include <bits/stdc++.h>

using namespace std;

int solve (int , int );

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif

    int l, r;
    cin >> l >> r;

    cout << solve(l, r) << endl; 


    return 0;
}

int solve (int l, int r) {
    
    for (int i = l; i <= r; ++i) {
        vector count(10, 0); 
        int temp = i;
        while (temp != 0) {
            count[temp%10]++;
            temp /= 10;
        }
        int index = 0;
        bool test = false;
        while (!test && index < 10) {
            if (count [index] > 1) test = true;
            index++;
        }
        if (!test) return i;
    }
    
    return -1;



}
