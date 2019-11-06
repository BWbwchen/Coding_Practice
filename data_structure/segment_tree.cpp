/*
    We have an array arr[0 . . . n-1].
    We should be able to
    1 Find the sum of elements from index l to r ,
        where 0 <= l <= r <= n-1
    2 Change value of a specified element of the array to a new value x.
        We need to do arr[i] = x where 0 <= i <= n-1.
*/
#define DEBUG
#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
int max_arr = 8;
int max_size, height;
int *seg_tree = NULL;



void build (int index, int begin, int end){

    if(begin == end){
        seg_tree[index] = arr[begin];
        return;
    }

    int mid = (begin + end)/2;

    //left
    build(2*index+1, begin, mid);

    //right
    build(2*index+2, mid+1, end);
    
    //left + right
    seg_tree[index] =  seg_tree[2*index+1] + seg_tree[2*index+2];
                  

}

void construct_tree (){
    //Allocate memory for the segment tree
    height = (int )(ceil(log2(max_arr)));
    
    //the size of segment tree
    max_size = ( 1 << (height+1) ) - 1;

    seg_tree = new int [max_size];
    for (int i = 0; i < max_size; ++i) seg_tree[i] = -1;

    build(0, 0, max_arr-1);
}

void update (int index, int shift,int begin,int end, int ind){
    if(shift == 0) return ;

    //at the leaf
    if(begin == end){
        arr[ind] += shift;
        seg_tree[index] += shift;
        return ;
    }

    int mid = (begin + end)/2;

    if(begin <= ind && ind <= mid){
        //if index is in the left leaf
        update (2*index+1, shift, begin, mid, ind);
    }else{
        //if index is in the right leaf
        update (2*index+2, shift, mid+1, end, ind);
    }

    seg_tree[index] = seg_tree[2*index+1] + seg_tree[2*index+2];

}
void output (){
    for(int i = 0; i < max_size; ++i){
        cout << seg_tree[i] << " ";
    }
    cout <<endl;
}

int query (int index, int begin, int end, int left, int right){
    //if 
    //right    begin
    //--|------|------
    //or
    //end    left
    //-|------|------
    if(right < begin || end < left){
        return 0;
    }

    //if the range is in the segment tree node
    if(left <= begin && end <= right){
        return seg_tree[index];
    }
    
    int mid = (begin + end)/2;
    int left_child = query (2*index+1, begin, mid, left, right);
    int right_child = query (2*index+2, mid+1, end, left, right);
    return left_child + right_child;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    //freopen ("text.out", "w", stdout);
    #endif
    

    construct_tree ();

    int left, right;
    cout << ">----------------answer--------------------<" << endl;
    //-1 will stop
    while(cin >> left >> right && left != -1){
        cout << "the sum in " << left << " to " << right 
        << " is :"<< query (0, 0, max_arr-1, left, right) << endl;
    }

    cout << ">----------------status--------------------<" << endl;
    output ();

    cout << ">-------------change value-----------------<" << endl;
    int ind, val;
    cin >> ind >> val;
    update(0, val-arr[ind], 0, max_arr-1, ind);// val > arr[ind]
    cout << ">----------------status--------------------<" << endl;
    output ();

    cout << ">----------------answer--------------------<" << endl;
    while(cin >> left >> right && left != -1){
        cout << "the sum in " << left << " to " << right 
        << " is :"<< query (0, 0, max_arr-1, left, right) << endl;
    }
    

    return 0;
}
/*
input:
0 1
2 6
-1 0
0 10
0 1
2 6
-1 0
*/