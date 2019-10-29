#define DEBUG
#include <bits/stdc++.h>

using namespace std;
class BiTree;
class Node {
    friend class BiTree;
    private :
        Node *left;
        int data;
        Node *right;
    public :
        Node (int t, Node *L = nullptr, Node *R = nullptr){
            data = t;
            left = L;
            right = R;
        }
};
class BiTree {
    private : 
        Node *root;

        Node* insert_by_level (vector<int > datas, int index, int limit) 
        {
            if (index < limit) {
                Node* temp = new Node(datas[index]);
                
                temp->left  = insert_by_level(datas, 2*index+1, limit);
                temp->right = insert_by_level(datas, 2*index+2, limit);

                return temp;
            }
            return nullptr;
            
        }
        
        void private_inorder (Node *temp_root) {
            if (temp_root) {
                private_inorder(temp_root->left);
                cout << temp_root->data << " ";
                private_inorder(temp_root->right);
            }
        }
        Node* copy (Node* original) {
            if (original == nullptr)  return nullptr;
            Node *temp_root = original;
            temp_root->left = copy(original->left);
            temp_root->right = copy(original->right);
            return temp_root;
        }
        bool is_equal (Node* first, Node *second) {
            return ((!first && !second) || 
                    (first && second && (first->data == second->data)) && 
                    is_equal(first->left, second->left) && 
                    is_equal(first->right, second->right) );
        }
    public:
        BiTree () {
            root = nullptr;
        }
        // input number left to right for each level
        void build () {
            int total, temp;
            cin >> total;
            vector<int > datas;
            for (int i = 0; i < total; ++i) {
                cin >> temp;
                datas.push_back(temp);
            }
            root = insert_by_level(datas, 0, total);
        }
        // recursive 
        void inorder_recursive() {
            private_inorder(root);
        }
        // stack
        void inorder_stack() {
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
        void level_order() {
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
        void copy_tree(BiTree original) {
            this->root = copy(original.root);
        }
        bool equal (BiTree test) {
            return is_equal(this->root, test.root);
        }
};

int main () {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 
    BiTree t;
    t.build();

    cout << "recursive inorder\n";
    t.inorder_recursive();
    cout << endl;
    
    cout << "stack inorder\n";
    t.inorder_stack();
    cout << endl;
    
    cout << "level order\n";
    t.level_order();
    cout << endl;

    cout << "copy tree\noriginal:";
    t.inorder_recursive();
    cout<< endl;
    cout << "copy version:";
    BiTree b;
    b.copy_tree(t);
    b.inorder_recursive();
    cout << endl;

    cout << "if two tree are equal ???\n";
    cout << "nullptr and t tree :";
    BiTree test;
    cout << t.equal(test) << endl;

    cout << "if copy is equal???\n";
    cout << t.equal(b) << endl;


    return 0;
}
