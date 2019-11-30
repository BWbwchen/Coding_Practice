#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>

using namespace std;

class Sort {
    private :
        vector<int > _unsort;
        vector<int > _sort;
        
        int make_position (int front, int end) {
            int small = front-1, big = front;
            // let pivot be the last one 
            while (big < end) {
                big++;
                if (_sort[big] < _sort[end]) 
                    swap(_sort[small++], _sort[big]);
            }
            // don't forget to let the pivot be middle!!!
            swap(_sort[small+1], _sort[end]);
            return small+1;
        }
        void quicksort(int front, int end) {
            if (front < end) {
                int pivot = make_position(front, end);
                quicksort(front, pivot-1);
                quicksort(pivot+1, end);
            }
        }
    public :
        Sort() {};
        void build() {
            int total, temp;
            cin >> total;
            for (int i = 0; i < total; ++i) {
                cin >> temp;
                _unsort.push_back(temp);
            }
        }
        void show () {
            for (auto a : _unsort) cout << a << endl;
        }
        // O(n^2)
        void insertion_sort() {
            // initial
            _sort = _unsort; 

            int right = -1;
            for (int i = 0; i < _sort.size(); ++i) {
                right++;
                int target = right;
                while (target >= 1) {
                    if (_sort[target] < _sort[target-1]) 
                        swap(_sort[target], _sort[target-1]);
                    target--;
                }
            }
            // print solution
            for (auto a : _sort) cout << a << endl;
        }
        void quick_sort() {  
            _sort = _unsort;
            quicksort(0, _unsort.size() - 1);
            // print solution 
            for (auto a : _sort) cout << a << endl;
        }
};

int main () 
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 

    Sort t;
    t.build();
    //t.show();
    //t.insertion_sort();
    t.quick_sort();

    return 0;
}

