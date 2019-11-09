#define DEBUG
#define MAXN 10001
#define PRE 1
#define IN 2
#define POST 3
#include <bits/stdc++.h>

using namespace std;

class BiTree;
class Node {
    friend class BiTree;
    private: 
        Node *left;
        int data;
        Node *right;
    public :
        Node (int d, Node* L = nullptr, Node* R = nullptr) {
            data = d;
            left = L;
            right = R;
        }
};

class BiTree {
    private :
        // variable
        Node *root;
        string s;
        int index;
        int total_number; // for check complete
        // function
        void inorder  (Node* );
        void preorder (Node* );
        void postorder(Node* );
        Node* insert ();
        int tree_height (Node* );
        bool check_complete (Node*, int);
        bool check_mirror (Node*, Node* );
        void free_tree(Node* );
        Node* delete_tree_leaf (Node* );
        long long int sum_up (Node*, map<Node*, long long int >& );
        long long int sum_of_grand(Node*, map<Node*, long long int> &);
    public :
        BiTree (){
            s = "";
            index = -1;
            root = nullptr;
            total_number = 0;
        }
        void clear () {
            free_tree(root);
            root = nullptr;
            s = "";
            index = -1;
            total_number = 0;
        }
        void build(string a) {
            s = a;
            root = insert();
            index = -1;
        }
        void travel(int method) {
            if (method == PRE) preorder(root);
            else if (method == IN) inorder(root);
            else postorder(root);
            cout << endl;
        }
        void height () {
            cout << tree_height(root) << endl;
        }
        void is_complete () {
            if (check_complete(root, 1)) cout << "Complete\n";
            else cout << "Not complete\n";
        }
        void is_foldable () {
            if (root == nullptr) cout << "Foldable\n";
            else if (check_mirror(root->left, root->right)) cout << "Foldable\n";
            else cout << "Not foldable\n";
        }
        void delete_leaf () {
            total_number = 0;
            root = delete_tree_leaf(root);
        }
        void QQaddition () {
            if (root == nullptr) {
                cout << "0\n";
                return ;
            }
            map<Node* , long long int > record;// record[Node] = the sum of Node and its gandchild

            long long int t = sum_up(root, record) ;
            if (t <= 0) cout << 0 << endl;
            else cout << t << endl;
            record.clear();
        }
};


int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	#ifdef DEBUG
	freopen("in.in", "r", stdin);
	#endif
    BiTree my_tree;
    string s;
    while (cin >> s) {
        my_tree.build(s);
        my_tree.travel(PRE);
        my_tree.travel(IN);
        my_tree.travel(POST);
        my_tree.height();
        my_tree.is_complete();
        my_tree.is_foldable();
        my_tree.QQaddition();
        my_tree.delete_leaf();
        my_tree.travel(PRE);
        my_tree.travel(IN);
        my_tree.travel(POST);
        my_tree.clear();
        s.clear();
    }

	return 0;
}

void BiTree::inorder (Node* temp_root) {
    if (temp_root) {
        inorder(temp_root->left);
        cout << temp_root->data << " ";
        inorder(temp_root->right);
    }
}
void BiTree::preorder (Node* temp_root) {
    if (temp_root) {
        cout << temp_root->data << " ";
        total_number ++;
        preorder (temp_root->left);
        preorder (temp_root->right);
    }
}
void BiTree::postorder(Node* temp_root) {
    if (temp_root) {
        postorder(temp_root->left);
        postorder(temp_root->right);
        cout << temp_root->data << " ";
    }
}
Node* BiTree::insert () {
    index++;
    if (s[index] == '(' ) {
        // (
        index++;
        if (s[index] == ')') return nullptr;
        Node *new_node = nullptr;
        // parse number
        string temp_num;
        if (s[index] == '-') {
            index++;
            while('0'<=s[index] && s[index]<='9') {
                temp_num.push_back(s[index]);
                index++;
            }
            index--;
            new_node = new Node(-1*stoi(temp_num));
        }
        else {
            while('0'<=s[index] && s[index]<='9') {
                temp_num.push_back(s[index]);
                index++;
            }
            index--;
            new_node = new Node(stoi(temp_num));
        }
        new_node->left = insert();
        new_node->right = insert();
        // )
        index++;
        return new_node;
    }
    return nullptr;
}
int BiTree::tree_height (Node* temp_root) {
    if (temp_root == nullptr) return 0;
    return max(tree_height(temp_root->left), tree_height(temp_root->right)) + 1;
}
bool BiTree::check_complete (Node* temp_root, int index) {
    if (temp_root == nullptr) return true; 

    if (index > total_number) return false;

    return check_complete(temp_root->left, 2*index) && 
           check_complete(temp_root->right,2*index+1);
}
bool BiTree::check_mirror (Node* n1, Node* n2) {
    if (n1 == nullptr && n2 == nullptr) return true;
    
    if (n1 == nullptr || n2 == nullptr) return false;

    return check_mirror(n1->left, n2->right) && check_mirror(n1->right, n2->left);
}
void BiTree::free_tree(Node* temp_root) {
    if (temp_root == nullptr) return ;
    free_tree(temp_root->left);
    free_tree(temp_root->right);
    delete temp_root;
}
Node* BiTree::delete_tree_leaf (Node* temp_root) {
    if (temp_root == nullptr) return nullptr;
    if (temp_root->left == nullptr && temp_root->right == nullptr) {
        delete temp_root;
        return nullptr;
    }
    temp_root->left = delete_tree_leaf(temp_root->left);
    temp_root->right = delete_tree_leaf(temp_root->right);
    return temp_root;
}
long long int BiTree::sum_up (Node* temp_root, map<Node*, long long int >& record) {
    if (temp_root == nullptr) return 0;

    if (record.find(temp_root) != record.end()) return record[temp_root];

    // build the record of this node
    long long int with_root = (long long int )temp_root->data + sum_of_grand(temp_root, record);
    long long int without_root = sum_up(temp_root->left, record) + sum_up(temp_root->right, record);

    record[temp_root] = max(with_root, without_root);
    return record[temp_root];
}
long long int BiTree::sum_of_grand (Node* temp_root, map<Node*, long long int>& record) {
    long long int sum = 0;
    if (temp_root->left) {
        sum += (sum_up(temp_root->left->left, record) +
                sum_up(temp_root->left->right,record) );
    }
    if (temp_root->right) {
        sum += (sum_up(temp_root->right->left, record) +
                sum_up(temp_root->right->right,record) );
    }
    return sum;
}
