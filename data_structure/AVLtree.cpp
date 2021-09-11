#define DEBUG
#include <bits/stdc++.h>

using namespace std;
class AVLTree;
class Node {
    friend class AVLTree;

   private:
    int _data;
    int _height;
    Node* left;
    Node* right;

   public:
    Node(int d, Node* L = nullptr, Node* R = nullptr) {
        _data = d;
        left = L;
        right = R;
        _height = 0;
    }
};

class AVLTree {
   private:
    Node* _root;
    Node* _insert(Node*, int);
    Node* _remove(Node*, int);
    Node* _left_rotate(Node*);
    Node* _right_rotate(Node*);
    Node* _balance_tree(Node*);
    void _inorder(Node*);
    int get_height(Node*);
    int _get_bf(Node*);

   public:
    AVLTree() { _root = nullptr; }
    void level_order();
    void inorder() { _inorder(_root); cout << endl; } ;
    void insert(int item) { _root = _insert(_root, item); };
    void remove(int key) { 
        cout << "====== remove " << key << " ===========" << endl;
        _root = _remove(_root, key); 
    };
    void print_info() {
        cout << "level order : " << endl;
        level_order();
        cout << "in order : (node data, height)" << endl;
        inorder();
    }
};

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    // LL
    cout << "============ LL cases ==========" << endl;
    AVLTree a;
    a.insert(6);
    a.insert(7);
    a.insert(4);
    a.insert(5);
    a.insert(2);
    a.insert(1);

    a.print_info(); 

    a.remove(4);
    a.print_info();
    a.remove(2);
    a.print_info();

    // LR
    cout << "============ LR cases ==========" << endl;
    AVLTree b;
    b.insert(6);
    b.insert(2);
    b.insert(4);

    b.print_info(); 

    // RR
    cout << "============ RR cases ==========" << endl;
    AVLTree c;
    c.insert(2);
    c.insert(1);
    c.insert(4);
    c.insert(3);
    c.insert(6);
    c.insert(5);

    c.print_info(); 

    c.remove(5);
    c.print_info();
    c.remove(6);
    c.print_info();

    // RL
    cout << "============ RL cases ==========" << endl;
    AVLTree d;
    d.insert(2);
    d.insert(4);
    d.insert(3);

    d.print_info(); 

    return 0;
}

//  insert item under root
//      think start from : i insert a node under a leaf node
//  and then make it balance
Node* AVLTree::_insert(Node* root, int item) {
    //  insert as binary search tree
    if (root == nullptr) return new Node(item);

    if (item <= root->_data)
        root->left = _insert(root->left, item);
    else if (root->_data < item)
        root->right = _insert(root->right, item);

    // balance it
    root->_height = get_height(root);
    root = _balance_tree(root);

    return root;
}

Node* AVLTree::_balance_tree(Node* root) {
    int bf = _get_bf(root);
    if (abs(bf) > 1) {
        // rebalance
        if (bf < 0) {
            // LL or LR
            int child_bf = _get_bf(root->left);

            // when the child is a complete tree, 
            // LL or LR is ok, but LL has less code.
            if (child_bf <= 0) {
                // LL
                cout << "LL" << endl;
                root = _left_rotate(root);

            } else {
                // LR
                cout << "LR" << endl;
                root->left = _right_rotate(root->left);
                root = _left_rotate(root);
            }
        } else {
            // RR or RL
            int child_bf = _get_bf(root->right);
            if (child_bf < 0) {
                // RL
                cout << "RL" << endl;
                root->right = _left_rotate(root->right);
                root = _right_rotate(root);
            } else {
                // RR
                cout << "RR" << endl;
                root = _right_rotate(root);
            }
        }
    }
    return root;
}

int AVLTree::_get_bf(Node* root) {
    int right_height = get_height(root->right);
    int left_height = get_height(root->left);
    return right_height - left_height;
}

int AVLTree::get_height(Node* root) {
    if (root == nullptr) return -1;
    int left_height = root->left ? root->left->_height : -1;
    int right_height = root->right ? root->right->_height : -1;
    return max(left_height, right_height) + 1;
}

//          a         b
//         /    =>     \
//        b             a
Node* AVLTree::_left_rotate(Node* root) {
    Node* new_root = root->left;
    Node* old_root = root;
    old_root->left = old_root->left->right;
    new_root->right = old_root;

    old_root->_height = get_height(old_root);
    new_root->_height = get_height(new_root);

    return new_root;
}

//          b           a
//           \   =>    /
//            a       b
Node* AVLTree::_right_rotate(Node* root) {
    Node* new_root = root->right;
    Node* old_root = root;
    old_root->right = new_root->left;
    new_root->left = old_root;

    old_root->_height = get_height(old_root);
    new_root->_height = get_height(new_root);

    return new_root;
}


Node* AVLTree::_remove(Node* root, int target) {
    //  insert as binary search tree
    if (root == nullptr) {
        cout << "Not found Here" << endl;
        return nullptr;
    }

    if (target < root->_data) {
        root->left = _remove(root->left, target);
    } else if (root->_data < target) {
        root->right = _remove(root->right, target);
    } else if (target == root->_data) {
        if (root->left) {
            root->_data = root->left->_data;
            root->left = _remove(root->left, root->left->_data);
        } else if (root->right) {
            root->_data = root->right->_data;
            root->right = _remove(root->right, root->right->_data);
        } else {
            free(root);
            return nullptr;
        }
    }
    root->_height = get_height(root);
    root = _balance_tree(root);

    return root;
}

void AVLTree::_inorder(Node* root) {
    if (root == nullptr) return ;
    _inorder(root->left);
    printf("(%d, %d) -> ", root->_data, root->_height);
    _inorder(root->right);
}

void AVLTree::level_order() {
    queue<Node*> q;
    q.push(_root);
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        cout << temp->_data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}
