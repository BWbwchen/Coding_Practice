#define DEBUG
#include <bits/stdc++.h>
#define LEFT 1
#define RIGHT -1

using namespace std;

using std::vector;
using std::set;
using std::list;
using std::cout;
using std::endl;


// A state contains five components:
// The first two components denote the current numbers of
// missionaries and cannibals at the left bank of the river.
// The third and fourth components denote the current numbers
// of missionaries and cannibals at the right bank.
// The fifth component denotes the location of the boat:
// 1 means "left bank" and -1 means "right bank".
using State = vector<int>;
class Crossing
{
private:
    vector<int> _npeople;  // how many missionaries and cannibals
                           // we use vector<int> as a tuple (int, int)
                           // the first integer indicate the number of missionariea
                           // the second integer indicates the number of cannibals
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    // specify the numbers of missionaries and cannibals
    Crossing(vector<int> np): _npeople {np} { }
    // the starting porint of your implementation
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[4] to indicate the direction of move
    State Go(State s, int missionary, int cannibal);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ")";
                    cout << "(" << s[2] << ", " << s[3] << ")";
                    if (s[4]==1) cout << " left\n";
                    else cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};

int main() {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif

    int X, Y; //Number of missionaries and cannibals
    cin >> X >> Y;
    Crossing p({X, Y});
    p.solve();
    p.show_solutions();
    
    
    
    return 0;
}


void Crossing::solve()
{
    list<State> initial;
    State init = _npeople;
    init.push_back(0);
    init.push_back(0);
    init.push_back(1);
    initial.push_back(init);
    _paths.insert(initial);

    while (!_paths.empty()) {
        set<list<State >> newpaths;
        set<list<State >> oldpaths;
        for (auto to_judge : _paths) {
            _explored.insert(to_judge.back());
            auto next_state = extend(to_judge.back());
            for (auto being_state : next_state) {
                if (found(being_state)) {
                    auto temp_path = to_judge;
                    temp_path.push_back(being_state);
                    _solutions.insert(temp_path);
                } else {
                    if (_explored.find(being_state) == _explored.end()) {
                        auto temp_path = to_judge;
                        temp_path.push_back(being_state);
                        newpaths.insert(temp_path); 
                    }
                }
            }
            oldpaths.insert(to_judge);
        }

        for (auto state : oldpaths) _paths.erase(state);
        for (auto state : newpaths) _paths.insert(state);
    }
}

// extend to other possible states from a certain state
set<State> Crossing::extend(State s)
{
    set<State> temp_state;
    if(valid(Go(s, 2, 0))) temp_state.insert(Go(s, 2, 0));
    if(valid(Go(s, 0, 2))) temp_state.insert(Go(s, 0, 2));
    if(valid(Go(s, 1, 1))) temp_state.insert(Go(s, 1, 1));
    if(valid(Go(s, 0, 1))) temp_state.insert(Go(s, 0, 1));
    if(valid(Go(s, 1, 0))) temp_state.insert(Go(s, 1, 0));
    return temp_state;
}
// may use s[4] to indicate the direction of move
State Crossing::Go(State s, int missionary, int cannibal)
{
    if ((s[4] == LEFT && s[0] >= missionary && s[1] >= cannibal) || 
        (s[4] == RIGHT && s[2] >= missionary && s[3] >= cannibal)) {
        s[0] -= s[4]*missionary;
        s[1] -= s[4]*cannibal;
        s[2] += s[4]*missionary;
        s[3] += s[4]*cannibal;
        s[4] = -s[4];
    }
    //printf ("in Go \n");
    //printf ("%d %d %d %d %d", s[0], s[1], s[2], s[3], s[4]);
    return s;
}
// check the validity of a state
bool Crossing::valid(State s)
{
    if ((s[0] >= s[1] || s[0] == 0)
        && (s[2] >= s[3] || s[2] == 0)) return true;
    else return false;
}
// check if all people are at the right bank
bool Crossing::found(State s)
{
    if (s[0] == 0 && s[1] == 0) return true;
    else return false;
}
