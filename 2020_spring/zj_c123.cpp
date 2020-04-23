// zero judge : https://zerojudge.tw/ShowProblem?problemid=c123
// UVA : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
#define DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
     * use queue and stack to simulate
     * key point: if you see the left side it seems like a queue !
     * but see the down side (stack), so if i pop a element from stack,
     * the left side queue pop a corresponding element too !
     * so we check if we can do the procedure above and make the queue empty,
     * if not, the permutation is wrong
     */
    int n;
    while (cin >> n) {
        int a;
        while (cin >> a) {
            if (a == 0) {
                cout << endl;
                break;
            }

            queue<int> li;
            li.push(a);
            for (int i = 1; i < n; ++i) {
                cin >> a;
                li.push(a);
            }

            stack<int> permute;
            int front_stack_element = 1;
            while (!li.empty()) {
                // try to push element into stack to mach
                // the top element with queue
                bool can_do = false;
                for (; front_stack_element <= n &&
                       front_stack_element <= li.front();
                     ++front_stack_element) {
                    can_do = true;
                    permute.push(front_stack_element);
                }
                if (!can_do && permute.top() != li.front()) {
                    cout << "No\n";
                    break;
                }
                while (!permute.empty() && !li.empty() &&
                       permute.top() == li.front()) {
                    permute.pop();
                    li.pop();
                }
            }
            if (li.empty()) cout << "Yes\n";
        }
    }

    return 0;
}
