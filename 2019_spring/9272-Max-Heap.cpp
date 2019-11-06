/*
    google heap stl
    and I use vector to implement heap.
*/
#define DEBUG
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    string cmd;
    int k;
    vector<int > heap;
    make_heap(heap.begin(), heap.end());

    while (cin >> cmd) {
        if (cmd == "PUSH") {
            cin >> k;
            heap.push_back(k);
            push_heap(heap.begin(), heap.end());
        } 
        else if (cmd == "POP") {
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        else if (cmd == "TOP"){
            if (heap.empty()) {
                cout << "NULL" << endl;
            }else cout << *(heap.begin()) << endl;
        }
        else {
            // fuck
        }
    }
    
    
    
    return 0;
}


