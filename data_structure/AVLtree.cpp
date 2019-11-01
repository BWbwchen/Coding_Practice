#define DEBUG
#include <bits/stdc++.h>

using namespace std;
class AVLTree;
class Node
{
friend class AVLTree;
    private:
        int _data;
        int _height;
        Node *left;
        Node *right;
    public :
        Node (int d, Node *L = nullptr, Node *R = nullptr) 
        {
            _data = d;
            left = L;
            right = R;
            _height = 0;
        }
};

class AVLTree 
{
    private : 
        Node *_root;
        Node* _insert (Node*, int );
        Node* _remove (Node*, int );
        int get_balence(Node* );
        int get_height (Node* c) 
        {
            if (c == nullptr) return -1;
            return 1 + max(get_height(c->left), get_height(c->right));
        }
    public :
        AVLTree () 
        {
            root = nullptr;
        }
        void level_order();
        void insert (int item) {root = insert(root, item);};
        void remove (int key) {root = remove(root, key);};

};

int main () 
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 
    AVLTree a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);

    a.level_order();
    cout << endl;

    a.remove(5);
    a.level_order();
    cout << endl;


    return 0;
}

void AVLTree::level_order() 
{
    queue<Node *> q;
    q.push(_root);
    while (!q.empty()) {
        auto temp = q.top();
        q.pop();
        cout << temp->_data << " " ;
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}
//  insert item under temp_root
//      think start from : i insert a node under a leaf node 
//  and then make it balance
Node* AVLTree::_insert (Node* temp_root, int item)
{
    //  insert as binary search tree
    if (temp_root == nullptr) return new Node (item);

    if (item <= temp_root->_data) temp_root->left = _insert(temp_root->left, item); 
    else if (temp_root->_data < item) temp_root->right = _insert(temp_root->right, item); 
    
    // balance it 
    int delta = get_balence(temp_root);

    return temp_root;
}
Node* AVLTree::_remove (Node* temp_root, int target)
{


}
