#define DEBUG
#include <bits/stdc++.h>

using namespace std;

class minheap {
    private :
        // start from 0 !!
        int *arr; // data array
        int capacity;
        int heap_size;

        bool is_full () {return (heap_size == capacity);};

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

            if (L < heap_size && arr[root]>arr[L])
                smallest = L;
            if (R < heap_size && arr[root]>arr[R])
                smallest = R;

            // check if need to heapify
            if (smallest != root) {
                // only swap the content 
                swap(arr[root], arr[smallest]);
                heapify(smallest);
            }
        }
    public :
        minheap(int c) {
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

};

int main () {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 

    minheap t(10);
    t.insert_heap(10);
    t.insert_heap(5);
    t.insert_heap(4);
    t.insert_heap(7);
    t.insert_heap(100);
    t.insert_heap(65);
    t.insert_heap(-5);
    t.insert_heap(9);
    t.insert_heap(8);
    cout << "original minheap:";
    t.print_heap();
    cout << endl;

    t.delete_index(0);
    cout << "delete the 6th node:";
    t.print_heap();
    cout << endl;


    return 0;
}
