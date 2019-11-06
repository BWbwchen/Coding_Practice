#define DEBUG
#include <bits/stdc++.h>

using namespace std;

class List_stack;

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ): data( info ), nextPtr( NULL ), prevPtr( NULL ){};
    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; 

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};

int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif
    
    List_stack L_stack;
    char command[10];
    int n;
    while(cin>>command){

        if(strcmp(command,"pop")==0){
            L_stack.pop();
        }else if(strcmp(command,"push")==0){
            cin >> n;
            L_stack.push(n);
        }else if(strcmp(command, "print") == 0){
            L_stack.print();
            cout << endl;
        }
    }

    return 0;
}

List_stack::List_stack()
{
    head = tail = nullptr;
}

List_stack::~List_stack()
{
    delete head;
}

void List_stack::pop()
{
    if (head == nullptr) {
        return;
    }
    else {
        //cout << head->data << endl;
        if (head->prevPtr != nullptr) head->prevPtr->nextPtr = nullptr;
        else {head = nullptr; tail = nullptr; return;}
        ListNode *d = head;
        head = head->prevPtr;
    }
}

void List_stack::push(const int &num)
{
    if (head == nullptr) {
        head = new ListNode(num);
        tail = head;
    }
    else {
        ListNode *now = new ListNode(num);
        head->nextPtr = now;
        now->prevPtr = head;
        head = now;
    }

}

void List_stack::print()
{
    for (ListNode *temp = head; temp != nullptr; temp = temp->prevPtr) {
        cout << temp->data << (temp->prevPtr!=nullptr?" ":"");
    }
}