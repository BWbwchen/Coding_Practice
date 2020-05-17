#include <vector>
#define DEBUG
#define MAXN 10000000
#include <bits/stdc++.h>
using namespace std;


string st, s;

void in_order (int index) {

    if (index >= s.size()) return ;
    if (s[index] == '0') {
        return ;
    }

    in_order(2*index + 1);
    st.push_back(s[index]);
    in_order(2*index + 2);

}

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int heap_size;
    cin >> heap_size;

    vector<int > a(heap_size, 0);
    for (int i = 0; i < heap_size; ++i) {
        cin >> a[i];
    }


    int t;
    cin >> t;
    string level, in;
    s.resize(heap_size, '0');
    while (t--) {
        level.clear(); in.clear();
        cin >> level >> in;
        for (int i = 0; i < heap_size; ++i) s[i] = '0';
        st.resize(0);

        

        int id = 0;
        for (int i = 0; i < heap_size; ++i) {
            if (a[i] && id < level.size()) {
                s[i] = level[id++];
            } 
        }

        in_order(0);


        if (in == st) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
