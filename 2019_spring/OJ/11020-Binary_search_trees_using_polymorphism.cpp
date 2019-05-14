#define DEBUG
#include <bits/stdc++.h>

using namespace std;

class BST{ // pure virtual 
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual bool search(const int &) const = 0;
    virtual void print() const = 0;
    int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

protected:
    int Height;
};

class Array_BST : public BST{
public:
    Array_BST();
    virtual ~Array_BST() {}
    virtual void insert(const int &) override; //root node is stored at index 1.
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int k = pow(2, height());
        for (int i = 1; i <= k-1; i++) {
            if (array[i] != 0)
                cout << array[i] << " ";
        }
    }

private:
    int array[1025];
};

class ListNode {
friend class List_BST; //make List_BST a friend
public:
    ListNode(const int &info):key( info ),left( nullptr ),right( nullptr ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};//end class ListNode

class List_BST : public BST {
public:
    List_BST();
    virtual ~List_BST()
    {
        deleteTree(root);
    }
    virtual void insert(const int &) override;
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int i;
        for(i = 1; i <= Height; i++){
            printGivenLevel(root, i);
        }
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const; //new a ListNode and return its address
    /* clean a tree.*/
    void deleteTree(ListNode *root);

    void printGivenLevel(ListNode* Ptr, int level) const {
        if (Ptr == nullptr)
            return;
        if (level == 1)
            cout << Ptr->key << " ";
        else if (level > 1)
        {
            printGivenLevel(Ptr->left, level-1);
            printGivenLevel(Ptr->right, level-1);
        }
    }
};

void BSTManipulator(BST& bstobj1,BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj1.insert(n);
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        
        if (bstobj1.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }else if (cmd == 'H'){
        cout << bstobj1.height() << endl;;
        cout << bstobj2.height() << endl;;

    }else if (cmd == 'P'){
        bstobj1.print();
        cout << endl;
        bstobj2.print();
        cout << endl;
    }
}

int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif
    Array_BST A_bst;
    List_BST B_bst;
    char cmd;
    while (cin >> cmd)
        BSTManipulator(A_bst, B_bst, cmd);

    return 0;
}


/*Implement 
 1. constructor
 2. insert()
 3. search() of both the Array_ BST and List_ BST 
 4. createLeaf(), deleteTree() of List_ BST class.
*/

/*
    Array
*/
Array_BST::Array_BST(): BST()
{
    memset(array, 0, 1025*sizeof(int ));
}

//root node is stored at index 1.
void Array_BST::insert(const int &num)  
{
    int index = 1;
    int temp_height = 1;
    while (array[index]) {
        temp_height++;
        if (num < array[index]) 
            index = 2*index;
        else if (num > array[index])
            index = 2*index+1;
        else break;
    }
    if (temp_height > Height) Height = temp_height;
    array[index] = num;
} 
bool Array_BST::search(const int &num) const  
{
    int index = 1;
    while (array[index]) {
        if (num < array[index]) 
            index = 2*index;
        else if (num > array[index])
            index = 2*index+1;
        else return true;
    }
    return false;
}

/*
    List
*/
List_BST::List_BST(): BST()
{
    root = nullptr;
}
void List_BST::insert(const int &num)  
{
    int temp_height = 1;
    ListNode *new_Node = createLeaf(num);
    if (root == nullptr) root = new_Node;
    ListNode *temp = root;
    while (temp) {
        temp_height++;
        if (num < temp->key)
            if (temp->left == nullptr) {temp->left = new_Node; break;}
            else temp = temp->left;
        else if (num > temp->key)
            if (temp->right == nullptr) {temp->right = new_Node; break;}
            else temp = temp->right;
        else break;
    }
    if (temp_height > Height) Height = temp_height;
}
bool List_BST::search(const int &num) const 
{
    ListNode *temp = root;
    while (temp) {
        if (num < temp->key) 
            temp = temp->left;
        else if (num > temp->key)
            temp = temp->right;
        else return true;
    }
    return false;
}
//new a ListNode and return its address
ListNode* List_BST::createLeaf(int key) const 
{
    ListNode *temp = new ListNode (key);
    return temp;
} 
void List_BST::deleteTree(ListNode *root)
{
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
