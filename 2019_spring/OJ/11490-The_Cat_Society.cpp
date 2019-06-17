#define DEBUG
#include <bits/stdc++.h>


using namespace std;

typedef struct {
    string name;
    int occup;
    int age;
} Cat;


bool cmp (const Cat& a, const Cat& b) {
    if (a.occup < b.occup) return true ;
    else if (a.occup > b.occup) return false;
    else {
        if (a.age == b.age) return a.name < b.name;
        else if (a.age < b.age) {
            if (a.occup == 5) return true ;
            else return false ;
        }
        else if (a.age > b.age) {
            if (a.occup == 5) return false ;
            else return true ;
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif

    int cat, food;
    string temp;
    while (cin >> cat >> food) {
        vector<Cat > t(cat);
        for (int i = 0; i < cat; ++i) {
            cin >> t[i].name;
            cin >> temp;
            cin >> t[i].age;
            switch (temp[0])
            {
            case 'e' : t[i].occup = 1; break;
            case 'n' : t[i].occup = 2; break;
            case 'k' : t[i].occup = 3; break;
            case 'w' : t[i].occup = 4; break;
            case 'a' : t[i].occup = 5; break;
            case 'm' : t[i].occup = 6; break;
            case 'd' : t[i].occup = 7; break;
            case 'l' : t[i].occup = 8; break;
            default : t[i].occup = 100; 
            }
        }
        sort (t.begin(), t.end(), cmp);
        if (food > cat ) food = cat;
        for (int i = 0; i < food; ++i) {
            cout << t[i].name << "\n";
        }
    }

    return 0;
}

