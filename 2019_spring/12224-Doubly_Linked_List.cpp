/*
(1) IH i : Insert a new integer i to the head of the list.

(2) IT i : Insert a new integer i to the tail of the list.

(3) RH : Print and remove the element in the head of the list. If the list is empty, print a blank line.

(4) RT : Print and remove the element in the tail of the list. If the list is empty, print a blank line.

(5) S : Swap the first floor(k/2) elements and the last k - floor(k/2) elements, where k is the total number of elements in the list. For example, if k = 5, the result of swapping a1, a2, a3, a4, a5 will be a3, a4, a5, a1, a2.
*/
#define DEBUG
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

bool Change_Middle = false;

typedef struct _Node {
    int data;
    struct _Node *pre;
    struct _Node *next;
} Node ;

Node *head = nullptr;
Node *tail = nullptr;
Node *middle = nullptr;

int total = 0;

void IH (int number)
{
    ++total;
    if (head == nullptr) {
        head = new Node;
        head->pre = nullptr;
        head->next = nullptr;
        head->data = number;
        tail = head;
        middle = head;
    }
    else {
        Node *ptr = new Node;
        ptr->data = number;
        ptr->pre = nullptr;
        ptr->next = head;

        head->pre = ptr;

        if (Change_Middle) middle = middle->pre;

        Change_Middle = !Change_Middle;
        
        head = ptr;
    }
}

void IT (int number) 
{
    if (tail == nullptr) {
        IH(number);
    }
    else {
        ++total;
        Node *ptr = new Node;
        ptr->data = number;
        ptr->pre = tail;
        ptr->next = nullptr;

        tail->next = ptr;

        if (!Change_Middle) middle = middle->next;

        Change_Middle = !Change_Middle;

        tail = ptr;
    }
}

void RH (void )
{
    if (head == nullptr) {
        cout << endl;
    }
    else {
        --total;
        cout << head->data << endl;
        Node *d = head;
        if (head == tail) head = nullptr;
        else {
            head->next->pre = nullptr;
            head = head->next;
        }

        if (head == nullptr) {
            tail = nullptr; 
            middle = nullptr;
            Change_Middle = false;
            delete d;
            return;
        }
        if (!Change_Middle) middle = middle->next;

        Change_Middle = !Change_Middle;

        delete d;
    }
}

void RT (void )
{
    if (tail == nullptr) {
        cout << endl;
    }
    else {
        --total; 
        cout << tail->data << endl;
        Node *d = tail;
        if (tail == head) tail = nullptr;
        else {
            tail->pre->next = nullptr;
            tail = tail->pre;
        }

        if (tail == nullptr) {
            head = nullptr;
            middle = nullptr;
            Change_Middle = false;
            delete d;
            return;
        }
        if (Change_Middle) middle = middle->pre;

        Change_Middle = !Change_Middle;
      
        delete d;
    }
}

void S (void )
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

void print (Node *temp) 
{
    for (; temp!=nullptr; temp = temp->next) {
        cout << temp->data << "->";
    }
    cout << "NULL\n";
    
    cout << "NULL";
    for (temp = tail; temp!=nullptr; temp = temp->pre) {
        cout << "->" << temp->data;
    }
    cout <<endl;
    for (temp = head; temp != nullptr; temp = temp->next) {
        if (temp == head) cout << "head : " << head->data << endl;
        if (temp == middle) cout << "middle : " << middle->data << endl;
        if (temp == tail) cout << "tail : " << tail->data << endl;
    }
}

int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif
    
    string cmd;

    while ( cin >> cmd ) {
        int data;
        if (cmd == "IH") {
            cin >> data;
            IH(data);
        }
        else if (cmd == "IT") {
            cin >> data;
            IT(data);
        }
        else if (cmd == "RH") {
            RH();
        }
        else if (cmd == "RT") {
            RT();
        }
        else if (cmd == "S") {
            cout << "---- before------\n";
            print(head);

            S();
            cout << "---- after-------\n";
            print(head);
        }
    }
    
    //print(head);

    return 0;
}