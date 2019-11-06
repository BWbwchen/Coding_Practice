#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
#ifdef DEBUG
    freopen ("in.in", "r", stdin);
#endif

    int len;
    string s;
    cin >> len >> s;
    
    int index = 0;
    int count = 1;

    while (index < len){
        cout << s[index];
        index += count;
        count ++;
    }

}
