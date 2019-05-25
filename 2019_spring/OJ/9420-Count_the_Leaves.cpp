#define DEBUG
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    
    map<int ,int > tree;
    int testcase, key, value, root;

    while (cin >> testcase && testcase) {
        while (testcase--) {
            cin >> key >> value;
            tree[key] = 1;
            tree[value] = 0;
        }
        cin >> root;
        
        if (tree[root] == 0) {
            cout << 0 << endl;
        }
        else {
            int ans = 0;
            for (auto id : tree) {
                if (id.second == 0) ans ++;
            }
            cout << ans << endl;
        }
        //remember to clear!
        tree.clear();
    }
    
    
    
    return 0;
}


