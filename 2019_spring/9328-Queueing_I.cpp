#define DEBUG
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    string cmd, k;
    queue<string > q;

    while (cin >> cmd) {
        if (cmd == "Push") {
            cin >> k;
            q.push(k);
        } 
        else if (cmd == "Pop") {
            if (!q.empty()) q.pop();
        }
        else if (cmd == "Front"){
            if (q.empty()) cout << "empty" << endl;
            else cout << q.front() << endl;
        }
        else {
            // fuck
        }
    }
    
    
    
    return 0;
}


