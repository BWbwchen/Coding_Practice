#define DEBUG
#define MAXN 1000000
#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif
    
    int query, black, white;
    int delta = 0; // if white 0, black 1
    cin >> query;

    // consider 4 Black, 5 White

    /*
        make the main centre line : WBWBWBWB or BWBWBWBW
        then make the remain block next to the centre line 
        if remain put to the begin and the end of the centre line
    */

    
 
    while (query--) {
        cin >> black >> white;
        int less = min(black, white), flag = (less==black)?1:0;
        int more = (flag==1)?white:black;

        if (more > 3*less+1) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        // centre line 
        for (int i = 1; i <= less; ++i, --more) {
            printf("2 %d\n", 2*i+flag);
            printf("2 %d\n", 2*i+flag+1);
        }

        // nearby block
        bool leak ;
        if (more > 0)  leak = false;
        else leak = true ;
        for (int i = 1; i <= less && !leak; ++i) {
            for (int j = 1; j <= 3 && !leak; j+=2) {
                more--;
                if (more == 0) leak = true;
                printf("%d %d\n", j, 2*i+flag);
            }
        }

        // remain
        for (int i = 1; i < 3 && more > 0; ++i, more--) {
            printf("2 %d\n", (i==1)?1+flag:2*less-1+flag);
        }
    }
 
    return 0;
}
