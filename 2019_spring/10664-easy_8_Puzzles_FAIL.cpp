/*
    !!! NOTICE !!! 
    This method is fail for large step case(?
    so it can't pass the oj's test!!!
    this code use a star algorithm but seem not work for OJ
*/
#define DEBUG
#include <bits/stdc++.h>
#define GOAL 1
#define INIT 0
#define MAXN 100000
#define UP 0
#define DOWN 1 
#define LEFT 2
#define RIGHT 3

using namespace std;
using MAP = vector<vector<int >>;

MAP g_goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
MAP g_init ;

int solve (MAP );
void calculate(MAP& );
set<MAP > extend (MAP );
MAP move (MAP , int, int , int );
int find_value (MAP , int, int, int);
void print (MAP );
bool ok(MAP );

int main() {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif

    int n, count = 0;
    cin >> n;
    MAP map;
    while (n--) {

        
        map.clear();
        count = 0;

        for (int i = 0; i < 3; ++i) {
            vector<int > row;
            for (int j = 0; j < 3; ++j) {
                int t;
                cin >> t;
                row.push_back(t);
            }
            map.push_back(row);
        }
        map.push_back({-1, 0, 0});

        g_init = map;
        calculate(map);
        
        // map[3][0] for to_start
        // map[3][1] for to_goal

        //solve
        count = solve(map);
        
        if (count >= 15) {
            printf("You'd better skip this game.\n");
        } else {
            printf("You can solve it within %d steps.\n", count);
        }
        
       //printf("%d\n", count);
    }



    return 0;
}

void print(MAP map) {
    printf("------------------map_state----------------------\n");
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            printf("%d ", map[row][col]);
        }
        printf("\n");
    }
    printf("the value\n");
    printf("%d %d %d\n", map[3][0], map[3][1], map[3][2]);
    printf("--------------END------------------\n");
}

int find_value  (MAP map, int row, int col, int map_type) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++ j) {
            if (map_type == GOAL ) {
                if (map[i][j] == g_goal[row][col]) return abs(row - i) + abs(col - j);
            }
            else if (map_type == INIT ) {
                if (map[i][j] == g_init[row][col]) return abs(row - i) + abs(col - j);
            }
        }
    }
    return -MAXN;
}

void calculate(MAP& map) {
    //map[3][0] = 0;
    map[3][1] = 0;
    map[3][2] = 0;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            /*
            if (map[row][col] != 0 && map[row][col] != g_init[row][col]) {
                map[3][0] += find_value (map, row, col, INIT);
            }
            */
            if (g_goal[row][col] != 0 && map[row][col] != g_goal[row][col]) {
                map[3][1]++; /*find_value (map, row, col, GOAL);*/
            }
            
        }
    }
    map[3][2] = (++map[3][0]) + map[3][1];
}


MAP move (MAP map, int row, int col, int type) {
    
    switch (type )
    {
    case UP:
        swap(map[row][col], map[row-1][col]);
        break;
    case DOWN:
        swap(map[row][col], map[row+1][col]);
        break;
    case LEFT:
        swap(map[row][col], map[row][col-1]);
        break;
    case RIGHT:
        swap(map[row][col], map[row][col+1]);
        break;
    }
    calculate(map);
    return map;
}

set<MAP > extend (MAP map) {
    set<MAP > to_return;
    int row = 0, col = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (map[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
    }

    // move up
    if (row > 0) to_return.insert(move(map, row, col, UP));
    // move down 
    if (row < 2) to_return.insert(move(map, row, col, DOWN));
    // move left
    if (col > 0) to_return.insert(move(map, row, col, LEFT));
    // move right 
    if (col < 2) to_return.insert(move(map, row, col, RIGHT));
    
    return to_return;
}

int solve (MAP map) {
    int step = 0;
    set<MAP > to_judge;
    to_judge.insert(map);
    
    while (!to_judge.empty() && step < 100) {
        MAP ready_to_insert ;
        int min_value = MAXN;
        //printf("!!!!!!!!!!NEW CASE !!!!!!!!!\n");
        for (auto submap : to_judge) {
            //printf("===============================\n");
            //printf("every sub map\n");
            //print(submap);
            if(ok(submap)) return step;
            if (submap[3][2] < min_value) {
                min_value = submap[3][2];
                ready_to_insert = submap;
            }
            //printf("===============================\n");
        }
        to_judge.erase(ready_to_insert);
        auto extend_map = extend(ready_to_insert);
        for (auto every_extend : extend_map) {
            if (ok(every_extend)) return step+1;
            to_judge.insert(every_extend);
        }
        step++;
    }

    return step;
}

bool ok(MAP map) {
    if (map[0] == g_goal[0] &&
        map[1] == g_goal[1] &&
        map[2] == g_goal[2] ) return true;

    return false;
}

