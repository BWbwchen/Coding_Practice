#define DEBUG
#include <iostream>

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
            q = new T[100];
            begin = -1;
            end = -1;
            total = 0;
        }
        inline bool empty() {return (total)?false:true;};
        inline int size() {return total;};
        T& front() {
            if (empty()) throw "empty!!!";
            return q[begin];
        }
        T& back() {
            if (empty()) throw "empty!!!";
            return q[end];
        }
        void push(const T& item);
        void pop();

};

int main () 
{
    #ifdef DEBUG 
    freopen("in.in", "r", stdin);
    #endif

    _queue<int > t;
    t.pop();
    t.pop();
    t.push(3);
    cout << t.front() << endl;
    cout << t.back() << endl;
    t.push(4);
    cout << t.front() << endl;
    cout << t.back() << endl;
    t.pop();
    cout << t.front() << endl;
    cout << t.back() << endl;
    cout << t.empty();
    t.pop();
    cout << t.front() << endl;
    cout << t.back() << endl;
    return 0;
}



template<class T>
void _queue<T>::push (const T& item)
{
    if (total == 100) {
        cout << "full" << endl;
        return;
    }

    if (begin == -1) {
        begin = 0;
    }
    q[++end] = item;
    total++;
}

template<class T>
void _queue<T>::pop ()
{
    if (empty()) return ;
    begin++;
    total--;
}
