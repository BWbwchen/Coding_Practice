#define DEBUG
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>


using namespace std;

class ListNode
{
    friend class OWList; //make OWList a friend
    friend class TWList; //make TWList a friend

public:
    ListNode( const int &info ) //constructor
    : data( info ), nextPtr( nullptr )
    {
    } //end ListNode constructor

private:
    int data; //data
    ListNode *nextPtr; // next node in list
}; //end class ListNode


class OWList // one - way List 
{
public:
    //default constructor
    OWList();
    //destructor
    ~OWList();
    //insert node at front of list
    void insertAtFront( const int &value );
    //remove node from front of list
    void removeFromFront();
    //is List empty?
    bool isEmpty() const;
    //display contents of List
    void print() const;

protected:
    ListNode *firstPtr; //pointer to first node
    ListNode *lastPtr;  //pointer to last node

}; // end class List

class TWList:public OWList
{
public:
    //default constructor
    TWList()
    :OWList()
    {
        /*It will still work correctly if you omit the constructor call of the base
          class in the above member initializer list. The compiler will invoke this
          default constructor of OWList implicitly.*/
    }
    //destructor
    ~TWList()
    {
        /*You don't need to delete the list again because the compiler
          will invoke the destructor of the base class OWList to do this.*/
    }
    //insert node at back of list
    void insertAtBack( const int &value );
    //delete node from back of list
    void removeFromBack();

};


int main()
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif

    TWList integerList;
    int command;
    int value; // store node value

    while (cin >> command)
    {
        switch(command)
        {
        case 1: // insert at beginning
            cin >> value;
            integerList.insertAtFront(value);
            break;
        case 2: // insert at end
            cin >> value;
            integerList.insertAtBack(value);
            break;
        case 3: // remove from beginning
            integerList.removeFromFront();
            break;
        case 4: // remove from end
            integerList.removeFromBack();
            break;
        }
    }
    integerList.print();
    cout<<endl;

    return 0;
}

/*
    OWList

    protected
    ListNode *firstPtr; //pointer to first node
    ListNode *lastPtr;
*/

//default constructor
OWList::OWList() : firstPtr(nullptr), lastPtr(nullptr) {};
//destructor
OWList::~OWList(){
    /* I don't wanna write :p */
}


//insert node at front of list
void OWList::insertAtFront( const int &value )
{
    if (firstPtr == nullptr) {
        // head 
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;    
    }
    else {
        ListNode *temp = new ListNode(value);
        temp->nextPtr = firstPtr;
        firstPtr = temp;
    }
}

//remove node from front of list
void OWList::removeFromFront()
{
    // nothing
    if (firstPtr == nullptr ) return ;
    // just one
    if (firstPtr == lastPtr) {
        firstPtr = nullptr;
        lastPtr = nullptr;
        return ;
    }
    //else 
    firstPtr = firstPtr->nextPtr;
}

//is List empty?
bool OWList::isEmpty() const
{
    if (firstPtr == nullptr) return true;
    else return false;
}

//display contents of List
void OWList::print() const
{
    ListNode *temp = firstPtr;
    while (temp != nullptr) {
        cout << temp->data << (temp->nextPtr==nullptr ? "" : " ") ;
        temp = temp->nextPtr;
    }
}

/* 
    TWList

    ListNode *firstPtr; //pointer to first node
    ListNode *lastPtr;
*/

//insert node at back of list
void TWList::insertAtBack( const int &value )
{
    if (firstPtr == nullptr && lastPtr == nullptr) {
        // head 
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;    
    }
    else {
        lastPtr->nextPtr = new ListNode(value);
        lastPtr = lastPtr->nextPtr ;
    }
}

//delete node from back of list
void TWList::removeFromBack()
{
    // nothing
    if (firstPtr == nullptr ) return ;
    // just one
    if (firstPtr == lastPtr) {
        firstPtr = nullptr;
        lastPtr = nullptr;
        return ;
    }
    //else 
    ListNode *temp = firstPtr;
    while (temp->nextPtr != lastPtr) temp = temp->nextPtr;
    temp->nextPtr = nullptr;
    lastPtr = temp;
}

