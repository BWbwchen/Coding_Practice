#define DEBUG
#include <bits/stdc++.h>

using namespace std;

class List;

class Node {
    friend List;
private :
    int data;
    Node *pre;
    Node *next;
public :
    Node () : data(0), pre(nullptr), next(nullptr){};
    Node (int a) : data(a), pre(nullptr), next(nullptr){};
};

class List{
private :
    Node *head;
    Node *middle;
    Node *tail;

    int total;
    bool Change_Middle ;

    void reset () {
        head = nullptr;
        middle = nullptr;
        tail = nullptr;
        total = 0;
        Change_Middle = false;
    }

    void clean () {
        Node *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

public :
    List () {
        reset();
    }

    ~List (){
        clean();
    }

    void InsertHead (const int number);
    void InsertTail (const int number);
    void RemoveHead (void );
    void RemoveTail (void );
    void Swap       (void );
    void print      (void );
};


int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif
    List L;
    string cmd;
    int data;

    while ( cin >> cmd ) {
        if (cmd == "IH") {
            cin >> data;
            L.InsertHead(data);
        }
        else if (cmd == "IT") {
            cin >> data;
            L.InsertTail(data);
        }
        else if (cmd == "RH") {
            try {
                L.RemoveHead();
            } catch (const out_of_range &e) {
                cout << endl;
            }
        }
        else if (cmd == "RT") {
            try {
                L.RemoveTail();
            } catch (const out_of_range &e) {
                cout << endl;
            }
        }
        else if (cmd == "S") {
            //cout << "---- before------\n";
            //L.print();

            L.Swap();
            //cout << "---- after-------\n";
            //L.print();
        }
    }
    
    //print(head);

    return 0;
}

void List::InsertHead (const int number)
{
    if (head == nullptr) {
        head = new Node (number);
        head->pre = nullptr;
        head->next = nullptr;

        tail = head;
        middle = head;
    }
    else {
        Node *ptr = new Node(number);
        ptr->pre = nullptr;
        ptr->next = head;
        head->pre = ptr;
        head = ptr;

        if (Change_Middle) middle = middle->pre;

        Change_Middle = !Change_Middle;
    }
    ++total;
}

void List::InsertTail (int number) 
{
    if (tail == nullptr) {
        tail = new Node (number);
        tail->pre = nullptr;
        tail->next = nullptr;

        head = tail;
        middle = tail;
    }
    else {
        Node *ptr = new Node(number);
        ptr->pre = tail;
        ptr->next = nullptr;

        tail->next = ptr;
        tail = ptr;

        if (!Change_Middle) middle = middle->next;

        Change_Middle = !Change_Middle;
    }
    ++total;
}

void List::RemoveHead (void )
{
    if (head == nullptr) {
        throw out_of_range ("empty List");
    }
    else {
        cout << head->data << endl;
        Node *d = head;
        if (head == tail) {
            reset();
            return;
        }
        else {
            head->next->pre = nullptr;
            head = head->next;
        }

        if (!Change_Middle) middle = middle->next;

        Change_Middle = !Change_Middle;

        delete d;
    }
    --total;
}

void List::RemoveTail (void )
{
    if (tail == nullptr) {
        throw out_of_range ("empty List");
    }
    else {
        cout << tail->data << endl;
        Node *d = tail;
        if (tail == head) {
            reset();
            return;
        }
        else {
            tail->pre->next = nullptr;
            tail = tail->pre;
        }

        if (Change_Middle) middle = middle->pre;

        Change_Middle = !Change_Middle;
      
        delete d;
    }
    --total; 
}

void List::Swap (void )
{
    if (head == nullptr) return;
    if (head == tail) return;

    Node *temp = middle->pre;
    tail->next = head;
    head->pre = tail;

    head = middle;

    if (total%2) middle = tail;
    else middle = tail->next;

    tail = temp;
    head->pre = nullptr;
    tail->next = nullptr;
    
}

void List::print () 
{
    for (Node *temp = head; temp!=nullptr; temp = temp->next) {
        cout << temp->data << "->";
    }
    cout << "NULL\n";
    
    cout << "NULL";
    for (Node *temp = tail; temp!=nullptr; temp = temp->pre) {
        cout << "->" << temp->data;
    }
    cout <<endl;
    for (Node *temp = head; temp != nullptr; temp = temp->next) {
        if (temp == head) cout << "head : " << head->data << endl;
        if (temp == middle) cout << "middle : " << middle->data << endl;
        if (temp == tail) cout << "tail : " << tail->data << endl;
    }
}