#define DEBUG
#include <bits/stdc++.h>


using namespace std;


int calculate (void );


int main() {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif

    printf ("%d\n", calculate());

    return 0;
}

int calculate (void ) {
    stack<int > s;
    char c;
    int ans;

    while (1) {
        c = getchar ();
        
        if (c == '0') break;
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            int s1 = s.top();
            s.pop();
            int s2 = s.top();
            s.pop();
            switch (c)
            {
            case '+': ans = (s2 + s1); break;
            case '-': ans = (s2 - s1); break;
            case '*': ans = (s2 * s1); break;
            case '/': ans = (s2 / s1); break;
            }
            s.push (ans);
        }
        else if (c!='\n' && c!=' ') {
            int num;
            ungetc(c, stdin);
            cin >> num;
            
            s.push(num);
        }
    }

    return s.top();
}
