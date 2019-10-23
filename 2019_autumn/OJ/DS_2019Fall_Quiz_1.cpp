#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>
#define MAXIMUM 10000

using namespace std;


template<class T>
class _queue
{
    private:
        T* q;
        int begin, end;
        int total;
    public:
        _queue(){
            q = new T[MAXIMUM];
            begin = -1;
            end = -1;
            total = 0;
        }
        ~_queue() {
            delete [] q;
//            cout << "go job\n";
        }
        inline bool empty() {return (total == 0)?true:false;};
        inline int size() {return total;};
        T front() {
            if (empty()) throw "empty!!!";
            return q[begin];
        }
        T back() {
            if (empty()) throw "empty!!!";
            return q[end];
        }
        void push(const T& item);
        void pop();
        void clear() {
    //        begin = end = -1;
    //        total = 0;
            delete [] q;
        }

};

vector<int > solve (pair<int , int > , pair<int , int > );
bool valid (pair<int , int > );

vector<pair<int , int > > visited;

class Data {
    public :
        int row;
        int col;
        int cost;
        
        Data(pair<int , int > a,int count = 0) {
            row = a.first;
            col = a.second;
            cost = count;
        }
        Data() {
            row = 0;
            col = 0;
            cost = 0;
        }
};


int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	#ifdef DEBUG
	freopen("in.in", "r", stdin);
	#endif

	string a1;
	string a2;
    vector<int > path ;
    int count = 0;
	while (cin >> a1 >> a2) {
		pair<int, int > a (a1[0]-'a', a1[1]-'1');
		pair<int, int > b (a2[0]-'a', a2[1]-'1');
		
		path = solve(a, b);
        int smallest = MAXN;
        for (vector<int >::iterator it = path.begin(); it != path.end(); it++) {
           if (*it < smallest) smallest = *it; 
           //cout << *it << " ";
        }
		path.clear();
        visited.clear();
//        cout << "number " << ++count << "'s case: "; 
        cout << smallest << endl;
	}
	return 0;
}

bool valid (pair<int , int > test)
{
    if (0 > test.first || test.first > 7 || 0 > test.second || test.second > 7) {
        return false;
    }
    if (find(visited.begin(), visited.end(), test) == visited.end()) {
        // can't find
        return true;
    }
    return false;
}


vector<int > solve (pair<int , int > begin, pair<int , int > end ) 
{
    _queue<Data > to_judge;
    pair<int , int > temp;
    vector<int > record;

    to_judge.push(Data(begin));
    // int count = 0;
    while(!to_judge.empty()) {
        //cout << count++ << endl;
        auto to_extend = to_judge.front();
        to_judge.pop();
        pair<int , int > t = {to_extend.row, to_extend.col};
        if ( t == end) {
            record.push_back(to_extend.cost);
            continue;
        }
        visited.push_back({to_extend.row, to_extend.col});
        
        // extend
        temp = {to_extend.row+2, to_extend.col+3};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
        temp = {to_extend.row-2, to_extend.col+3};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
        temp = {to_extend.row+2, to_extend.col-3};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
        temp = {to_extend.row-2, to_extend.col-3};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));

        temp = {to_extend.row+3, to_extend.col+2};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
        temp = {to_extend.row-3, to_extend.col+2};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
        temp = {to_extend.row+3, to_extend.col-2};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
        temp = {to_extend.row-3, to_extend.col-2};
        if (valid(temp)) to_judge.push(Data(temp, to_extend.cost+1));
    }
    //to_judge.clear();
    return record;
}


template<class T>
void _queue<T>::push (const T& item)
{

    if (begin == -1) {
        begin = 0;
    }
    end = (end+1)%MAXIMUM;
    q[end]= item;
    total++;
}

template<class T>
void _queue<T>::pop ()
{
    if (begin == -1 || begin > end) return ;
    // begin > end : think about just one node and want to pop it
    begin = (begin+1)%MAXIMUM;
    total--;
}
