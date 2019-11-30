#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>

using namespace std;
class Heap {
    private :
        // start from 0 !!
        int *arr; // data array
        int capacity;
        int heap_size;

        bool is_full () {return (heap_size==capacity && heap_size != 0);};

        // index's parent
        int parent(int index) {return (index-1)/2;};
        // index node's right
        int right (int index) {return index*2+2;};
        // index node's left
        int left (int index) {return index*2+1;};

        // heapify the subtree of given subtree
        void heapify(int root) {
            int smallest = root;
            int L = left(root);
            int R = right(root);

            // find the minmum number from 
            // arr[root], arr[L], arr[R]
            if (L < heap_size && arr[L] < arr[smallest]) 
                smallest = L;
            if (R < heap_size && arr[R] < arr[smallest])
                smallest = R;

            // check if need to heapify
            if (smallest != root) {
                // only swap the content 
                swap(arr[root], arr[smallest]);
                heapify(smallest);
            }
        }
    public :
        Heap () {
            capacity = 0;
            arr = nullptr;
            heap_size = 0;
        }
        Heap(int c) {
            capacity = c;
            arr = new int [capacity];
            heap_size = 0;
        }
        void setting(int c) {
            capacity = c;
            arr = new int [capacity];
            heap_size = 0;
        }


        void insert_heap(int val) {
            if (is_full()) return ;

            // put at the end
            arr[heap_size] = val;
            heap_size++;
            // make the heap
            int judge_index = heap_size-1;
            while(judge_index != 0 && arr[parent(judge_index)]>arr[judge_index]) {
                swap(arr[parent(judge_index)], arr[judge_index]);
                judge_index = parent(judge_index);
            }
        }
        void print_heap() {
            for (int i = 0; i < heap_size; ++i) {
                cout << arr[i] << " ";
            }
        }
        // this function delete the index of node
        void delete_index (int index) {
            if (index >= heap_size) return ;
            // delete that node
            arr[index] = 0;
            // let the last node be there
            arr[index] = arr[heap_size-1];
            heap_size--;
            // heapify
            heapify(index);
        }
        // this function delete root node
        void delete_root () {
            // delete that node
            // let the last node be there
            arr[0] = arr[heap_size-1];
            heap_size--;
            // heapify
            heapify(0);
        }
        int get_root() {return arr[0];};
};

class Sort {
    private :
        vector<int > _unsort;
        vector<int > _sort;
        Heap h;
        
        int make_position (int front, int end) {
            // TODO : let pivot be the median in O(1)
            int small = front-1;
            // let pivot be the last one 
            for (int big = front; big < end; ++big) {
                if (_sort[big] < _sort[end]) {
                    swap(_sort[++small], _sort[big]);
                }
            }
            // don't forget to let the pivot be middle!!!
            swap(_sort[small+1], _sort[end]);
            return small+1;
        }
        // O(logn) && O(n) = O(nlogn)
        // recursive && make pivot
        void quicksort(int front, int end) {
            if (front < end) {
                int pivot = make_position(front, end);
                quicksort(front, pivot-1);
                quicksort(pivot+1, end);
            }
        }
        void merge (int front, int mid, int end) {
            // need to consider only one 
            vector<int > left(_sort.begin()+front, _sort.begin()+mid+1),
                        right(_sort.begin()+mid+1, _sort.begin()+end+1);
            left.insert(left.end(), MAXN);
            right.insert(right.end(), MAXN);

            int Lindex = 0, Rindex = 0;
            for (int i = front; i <= end; ++i) {
                if (left[Lindex] < right[Rindex]) 
                    _sort[i] = left[Lindex++];
                else 
                    _sort[i] = right[Rindex++];
            }
        }
        void mergesort(int front, int end) {
            if (front < end) {
                int mid = (front + end)/2;
                mergesort(front, mid);
                mergesort(mid+1, end);
                merge(front, mid, end);
            }
        }

        // sort by num/nul %10
        void countingsort(int mul) {
            // counting
            vector<int > counting(10, 0);
            for (int i = 0; i < _unsort.size(); ++i) {
                counting[(_sort[i]/mul)%10]++;
            }

            // accumulate so assign sort array will more easier
            for (int i = 1; i < counting.size(); ++i) 
                counting[i] += counting[i-1];

            vector<int > temp_ans(_sort.size(), 0);
            // NOTICE HERE
            for (int i = _unsort.size() - 1; i >= 0; --i) {
                temp_ans[counting[(_sort[i]/mul)%10]-1] = _sort[i];
                counting[(_sort[i]/mul)%10]--;
            }

            _sort = temp_ans;
        }
    public :
        Sort() {};
        void build() {
            int total, temp;
            cin >> total;
            h.setting(total);
            for (int i = 0; i < total; ++i) {
                cin >> temp;
                _unsort.push_back(temp);
                _sort.push_back(temp);
                h.insert_heap(temp);
            }
        }
        void show () {
            for (auto a : _sort) cout << a << " ";
            cout << endl;
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
            show();
        }
        void quick_sort() {  
            _sort = _unsort;
            quicksort(0, _sort.size() - 1);
            // print solution 
            show();
        }
        void merge_sort () {
            _sort = _unsort;
            mergesort(0, _sort.size()-1);
            // print solution 
            show();
        }
        void heap_sort() {
            _sort.clear();
            for (int i =0; i < _unsort.size(); ++i) {
                // delete the root
                _sort.push_back(h.get_root());
                h.delete_root();
            }
            // print solution
            show();
        }
        void counting_sort() {
            // find min max
            int min = MAXN, max = -MAXN;
            for (int i = 0; i < _unsort.size(); ++i) {
                if (_unsort[i] < min) min = _unsort[i];
                if (_unsort[i] > max) max = _unsort[i];
            } 
            // counting
            vector<int > counting(max-min+1);
            fill(counting.begin(), counting.end(), 0);
            for (int i = 0; i < _unsort.size(); ++i) {
                counting[_unsort[i]-min]++;
            }
            // print the answer !
            for (int i = 0; i < counting.size(); ++i) {
                for (int j = 1; j <= counting[i]; ++j) {
                    cout << min+i << " ";
                }
            }
            cout << endl;
        }
        void radix_sort () {
            _sort = _unsort;
            // find the max
            int max = -MAXN;
            for (int i = 0; i < _unsort.size(); ++i) {
                if (_unsort[i] > max) max = _unsort[i];
            }
            
            int mul = 1;
            while (max) {
                countingsort(mul);
                mul *= 10;
                max /= 10;
            }
            show();
        }
};

int main () 
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 

    Sort t;
    t.build();
    cout << "unsort\n";
    t.show();
    cout << "insertion  sort\n";
    t.insertion_sort();
    cout << "quick  sort\n";
    t.quick_sort();
    cout << "merge  sort\n";
    t.merge_sort();
    cout << "heap  sort\n";
    t.heap_sort();
    cout << "counting  sort\n";
    t.counting_sort();
    cout << "radix  sort\n";
    t.radix_sort();
    

    return 0;
}

/*
testcase
27
11 10 9 8 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/
