#define DEBUG
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    int testcase = 0, i = 1;
    stack<char > s;
    string a;

    cin >> testcase;
    getchar();
    while (testcase--) {
        getline(cin, a);

        if (a.empty()) {
            cout << "Case " << i++ << ": " << "Yes" << endl;
            continue;
        }
        
        for (auto temp : a) {
            if (temp == '{' || temp == '[' || temp == '(' || temp == '<') {
                s.push(temp);
            }
            else {
                if (temp == '}') {
                    if (s.empty() || s.top() != '{') s.push(temp);
                    else s.pop();
                }
                else if (temp == ']') {
                    if (s.empty() || s.top() != '[') s.push(temp);
                    else s.pop();
                }
                else if (temp == ')') {
                    if (s.empty() || s.top() != '(') s.push(temp);
                    else s.pop();
                }
                else if (temp == '>') {
                    if (s.empty() || s.top() != '<') s.push(temp);
                    else s.pop();
                }
            }
        }
        if (s.empty()) cout << "Case " << i++ << ": " << "Yes" << endl;
        else cout << "Case " << i++ << ": " << "No" << endl;

        while (!s.empty()) s.pop();
        a.clear();
    }
    
    
    
    return 0;
}

/*
    if you got rumtime error
    think about the case:
    ][]
*/
