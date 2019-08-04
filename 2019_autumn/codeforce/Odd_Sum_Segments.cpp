#define DEBUG
#include <bits/stdc++.h>
 
using namespace std;
 
int main ()
{
    #ifdef DEBUG
    freopen("in.in", "r", stdin);
    #endif
    int queries, total, segment, temp;
    cin >> queries;
 
 
    while (queries--) {
        cin >> total >> segment;
        vector<int > sequence(total);
 
        // count for odd number
        int odd_count = 0;
        
        for (int i = 0; i < total; ++i) {
            cin >> sequence[i];
            odd_count += sequence[i]%2;
        }

        // for the last one if the number of odd is even then print NO  
        if (odd_count < segment || (odd_count-segment+1)%2 == 0) {
            cout << "NO\n";
        } else {


            // the first k-1 segment will be print
            cout << "YES\n";
            // print the first k-1 segment 
            for (int i = 0; i<total && segment!=1; ++i) {
                if (sequence[i]%2) {
                    segment--;
                    cout << i+1 << " ";
                }
            }
            cout << total << endl;
        }
 
    }
 
    return 0;
}