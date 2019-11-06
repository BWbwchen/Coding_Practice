#define DEBUG
#include <bits/stdc++.h>

using namespace std;

class ListNode{
    friend class List_BST; //make List_BST a friend

public:
    ListNode(const int &info):key( info ),left( NULL ),right( NULL ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};

class BST{
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual void remove(const int &) = 0;
    virtual bool search(const int &) const = 0;
    virtual void print()  = 0;
    virtual int height2() = 0;
    //virtual int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

    int Height;
};

//end class ListNode

class List_BST : public BST{
public:
    List_BST();
    virtual ~List_BST()
    {
        deleteTree(root);
    }
    virtual void insert(const int &) override;
    virtual void remove(const int &) override;
    virtual bool search(const int &) const override;
    virtual void print() override{
        int i;
        Height = calculateH(root);
        for(i = 1; i <= Height; i++){
            printGivenLevel(root, i);
        }
    }
    virtual int height2() {
        Height = calculateH(root);
        return Height;
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const;
    /* clean a tree.*/
    void deleteTree(ListNode *root){};

    void printGivenLevel(ListNode* Ptr, int level) const {
        if (Ptr == NULL)
            return;
        if (level == 1)
            cout << Ptr->key << " ";
        else if (level > 1)
        {
            printGivenLevel(Ptr->left, level-1);
            printGivenLevel(Ptr->right, level-1);
        }
    }
    int calculateH(ListNode* root)const{
        if (root==nullptr){
            return 0;
        }
        else{
            int ldepth = calculateH(root->left);
            int rdepth = calculateH(root->right);
            if(ldepth>rdepth) return(ldepth+1);
            else return(rdepth+1);
        }
    }
};



void BSTManipulator(BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }else if (cmd == 'H'){
        cout << bstobj2.height2() << endl;;

    }else if (cmd == 'P'){
        bstobj2.print();
        cout << endl;
    }else if (cmd == 'R'){
        cin >> n;
        bstobj2.remove(n);
    }
}


int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    List_BST B_bst;
    char cmd;

    while (cin >> cmd)
        BSTManipulator(B_bst, cmd);
    
    
    
    return 0;
}


List_BST::List_BST()
{
    root = nullptr;
}
    
void List_BST::insert(const int &num) 
{
    ListNode *temp = createLeaf(num);
    if (root == nullptr) {
        root = temp;
        return;
    } 
    ListNode *findNode = root;
    while (findNode != nullptr) {
        if (num < findNode->key) {
            if (findNode->left == nullptr) {findNode->left = temp; return;}
            else findNode = findNode->left;
        }
        else if (num > findNode->key) {
            if (findNode->right == nullptr) {findNode->right = temp; return;}
            else findNode = findNode->right;
        }
        else return;
    }
}
void List_BST::remove(const int &num) 
{
    ListNode *findNode = root, *parent = nullptr;
    bool isleft = false;

    while (findNode) {
        if (num < findNode->key) {
           parent = findNode;
           findNode = findNode->left;
           isleft = true;
        }
        else if (findNode->key < num) {
           parent = findNode;
           findNode = findNode->right;
           isleft = false;
        }
        else {
            if (findNode->left == nullptr && findNode->right == nullptr) {
                if (findNode == root) {
                    root = nullptr;
                    return;
                }
                if (isleft) parent->left = nullptr;
                else parent->right = nullptr;
            }
            else if (findNode->left == nullptr) {
                if (findNode == root) {
                    root = findNode->right;
                    return;
                }
                if (isleft) parent->left = findNode->right;
                else parent->right = findNode->right; 
            }
            else if (findNode->right == nullptr) {
                if (findNode == root) {
                    root = findNode->left;
                    return;
                }
                if (isleft) parent->left = findNode->left;
                else parent->right = findNode->left; 
            }
            else {
                // find min
                ListNode *min = findNode->right;
                ListNode *parent_min = findNode;
                int count = 0; // for detect whether the min is the next Node of findNode
                while (min) { 
                    count++;
                    if (min->left == nullptr) break;
                    parent_min = min;
                    min = min->left;
                }

                //copy
                findNode->key = min->key;
                
                // redirect
                if (count == 1) {
                    parent_min->right = min->right;
                }else parent_min->left = min->right;
            }
            return;
        }
    }
    return;
}
bool List_BST::search(const int &num) const 
{
    ListNode *findNode = root;
    if (root == nullptr) return false;
    while (findNode != nullptr) {
        if (num < findNode->key) {
            findNode = findNode->left;
        }
        else if (num > findNode->key) {
            findNode = findNode->right;
        }
        else return true;
    }
    return false;
}
ListNode* List_BST::createLeaf(int key) const
{
    ListNode *now = new ListNode (key);
    return now;
}
