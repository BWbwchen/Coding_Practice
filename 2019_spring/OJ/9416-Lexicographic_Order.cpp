#define DEBUG
#include <bits/stdc++.h>

using namespace std;


bool mycmp (string const &a, string const &b) {
    // because the cmp function of std::sort
    // can only use bool 
    if (a.compare(b) <= 0) return true;
    else return false;
}

int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    int testcase;
    string temp;
    vector<string > s;

    while (cin >> testcase && testcase) {
        // input
        while (testcase--) {
            cin >> temp;
            s.push_back(temp);
        }
        //sort 
        sort(s.begin(), s.end(), mycmp);
        //output
        for (auto a : s) cout << a << endl;
        //don't forget to clear origin vector
        s.clear();
        cout << endl;
    }
    return 0;
}


