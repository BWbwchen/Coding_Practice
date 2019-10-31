#define DEBUG
#include <bits/stdc++.h>

using namespace std;
class BiTree;
class Node 
{
    friend class BiTree;
    private :
        Node *left;
        int data;
        int leftsize;
        Node *right;
    public :
        Node (int t, Node *L = nullptr, Node *R = nullptr)
        {
            data = t;
            left = L;
            right = R;
            leftsize = 0;
        }
};
class BiTree 
{
    private : 
        Node *root;

        
        void private_inorder (Node *temp_root) 
        {
            if (temp_root) {
                private_inorder(temp_root->left);
                cout << temp_root->data << " ";
                private_inorder(temp_root->right);
            }
        }

        // the main point is 
        // i will insert the node under that node
        Node *_insert(Node* that, int data) 
        {
            if (that == nullptr) return new Node(data);

            if (data < that->data) that->left = _insert(that->left, data);
            else if (that->data < data) that->right = _insert(that->right, data);

            return that;
        }

        int findMax(Node *subroot)  
        {
            // left the max value of the given subroot tree
            Node *temp = subroot; 
            while (temp->right) temp = temp->right;
            return temp->data;
        }
    public:
        BiTree () 
        {
            root = nullptr;
        }

        // recursive 
        void inorder_recursive();

        // stack
        void inorder_stack();

        void level_order() ;
        
        // binary tree insert
        // using recursive
        void insert(int data) 
        {
            root = _insert(root, data) ;
        }

        bool search (int data)
        {
            Node *travel = root;
            while (travel) {
                if (data < travel->data) travel = travel->left;
                else if (travel->data < data) travel = travel->right;
                else return true;
            }
            return false;
        }
        // IMPORTANT!! if same value go to left
        void remove (Node *r, Node *parent, int target_value)
        {
            if (r == nullptr) return;

            if (target_value == r->data) {
                // leaf
                if (!r->left && !r->right) {
                    // if root
                    if (r == root) {root = nullptr; return;};
                    // parent link
                    if (target_value <= parent->data) parent->left = nullptr;
                    else parent->right = nullptr;
                    //delete r;
                }
                // degree one 
                else if (r->right == nullptr) {
                    // if root 
                    if (r == root) {root = root->left; return;};
                    // only left
                    // why use <= 
                    // = is rule for same to left tree !!
                    if (target_value <= parent->data) parent->left = r->left;
                    else parent->right = r->left;
                    // delete r;
                }
                else if (r->left == nullptr) {
                    // if root
                    if (r == root) {root = root->right; return;};
                    // only right
                    if (target_value <= parent->data) parent->left = r->right;
                    else parent->right = r->right;
                    // delete r;
                }
                // degree two
                else {
                    // find the max in left subtree
                    int d = findMax(r->left); 
                    // copy to the r
                    r->data = d;
                    // delete that leaf node
                    remove(r->left, r, d);
                }
            }
            else if (target_value < r->data) {
                remove(r->left, r, target_value);
            }
            else remove(r->right, r, target_value);
        }
        void remove_er (int target_value) {
            if (!search(target_value)) return ;
            remove (root, root, target_value);
        }
        void print_root() {
            if (root) cout << "root is : " << root->data << endl;
            else cout << "is empty!!\n";
        }
};

int main () 
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 
    BiTree t;
    t.insert(1);
    t.insert(0);
    t.insert(8);
    t.insert(5);
    t.insert(9);
    t.insert(3);
    t.insert(4);

    cout << "recursive inorder\n";
    t.inorder_recursive();
    cout << endl;

    cout << boolalpha;
    cout << "search for 9: " << t.search(9);
    cout << endl;
    cout << "search for 0: " << t.search(0);
    cout << endl;


    // delete
    cout << "test for delete\n";
    t.remove_er(1);
    t.inorder_recursive();
    cout << endl;
    t.print_root();
    cout << endl;

    return 0;
}
void BiTree::inorder_recursive() 
{
    private_inorder(root);
}
// stack
void BiTree::inorder_stack() 
{
    //  left -> root -> right
    // same as recursive method
    stack<Node*> s;
    Node *temp_root = root;
    while (1) {
        while (temp_root) { // go to left left node 
            s.push(temp_root);
            temp_root = temp_root->left;
        }
        if (s.empty()) return ;
        temp_root = s.top();
        s.pop();
        cout<< temp_root->data << " " ;
        // think for the last 2 level node who have left nullptr and right node  
        temp_root = temp_root->right; 
    }
}
void BiTree::level_order() 
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto temp_top = q.front();
        q.pop();
        // visit !
        cout << temp_top->data << " ";
        //expand
        if (temp_top->left)  q.push(temp_top->left);
        if (temp_top->right) q.push(temp_top->right);
    }
}
