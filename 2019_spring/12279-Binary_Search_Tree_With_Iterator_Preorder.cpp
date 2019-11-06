/*
    if have no idea 
    google binaty tree travel without recursion
*/
#define DEBUG
#include <bits/stdc++.h>

using namespace std;


struct Node
{
    int value;
    Node *right;
    Node *left;

    Node(int v)
        :value(v)
        ,right(nullptr)
        ,left(nullptr) {}
    
    ~Node()
    {
        delete right;
        delete left;
    }
};

class Iterator
{
public:
    void *data;

    Iterator(Node *);
    Iterator(const Iterator &other);
    ~Iterator();
    int operator*() const;
    bool operator!=(const Iterator &) const;
    void operator++(int);
};


class BST
{
public:
    BST():m_root(nullptr){}
    ~BST(){delete m_root;}

    void push_back(int val)
    {
        Node **pos = &m_root;

        while( *pos )
        {
            if( (*pos)->value < val ) pos = &(*pos)->right;
            else pos = &(*pos)->left;
        }
        
        *pos = new Node(val);
    }
    
    Iterator begin()
    {
        Iterator it(m_root);
        return it;
    }

    Iterator end()
    {
        Iterator end(nullptr);
        return end;
    }

private:
    Node *m_root;
};




int main(int argc, char** argv) {
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif
    
    int G, N, tmp;
    
    BST bst;
    
    cin>>N>>G;
    
    for(int i=0;i<N;++i)
    {
        cin>>tmp;
        bst.push_back(tmp);
    }

    auto it = bst.begin();
    auto it2 = bst.begin();
    auto end = bst.end();
    while( it != end )
    {
        if( it2 != end ) it2++;
        if( it2 != end ) it2++;
        cout << *it + G << endl;
        it++;
    }
    
    
    
    return 0;
}

struct Content
{
    stack <Node *> st;
};


Iterator::Iterator(Node *root)
{
    data = new Content;
    ((Content *)data)->st.push(nullptr);
    ((Content *)data)->st.push(root);
}

Iterator::Iterator(const Iterator &other) // copy constructor
{
    ((Content *)data)->st = ((Content *)(other.data))->st;
}

Iterator::~Iterator()
{
    //fuck this
}

int Iterator::operator*() const
{
    return (((Content *)data)->st.top())->value;
}

bool Iterator::operator!=(const Iterator &it) const
{
    return ((Content *)data)->st.top()!=((Content *)(it.data))->st.top();
}

void Iterator::operator++(int dummy)
{
    Node *root = ((Content *)data)->st.top();
    ((Content *)data)->st.pop();
    if (root->right) ((Content *)data)->st.push(root->right);
    if (root->left) ((Content *)data)->st.push(root->left);
}
