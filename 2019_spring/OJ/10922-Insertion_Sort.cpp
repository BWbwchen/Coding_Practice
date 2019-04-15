#define DEBUG
#include <bits/stdc++.h>
//can try use vector to do 
using namespace std;

void swap (int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}


int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif
    
    int case_number, answer = 0;
    cin >> case_number;
    
    while (case_number--) {

        int total;
        cin >> total;
        int record[total];
        for (int i = 0; i < total; ++i) cin >> record[i];

        for (int i = total-1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (record[j] > record[j+1]) {
                    swap(record[j], record[j+1]);
                    answer++;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}