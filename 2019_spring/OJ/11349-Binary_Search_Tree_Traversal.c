//WARNING!!! this code hasn't finished yet!!
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;
//??????????????????/
void travel(Node **temp, int goal){
    Node *ptr = *temp;
    if(temp->left == NULL || temp->right == NULL) return;
    while(1){
        if(goal < ptr->data){
            
        }else if(ptr->data < goal){

        }
    }
}

/*
    if you call create() and give it root and number
    it will build the tree
*/
void create(Node **root, int times){
//  if no data
    if(times == 0) return ;
//  temp will travel to the what root i want
    Node *temp = *root;
    Node *new = (Node *)malloc(sizeof(Node ));

    int num;
    scanf("%d", &num);
    new->data = num;

    if((*root) == NULL){
        *root = new;
        (*root)->left = NULL;
        (*root)_>right = NULL;
        create(root, times-1);
        return;
    }
//  travel  to what Node i want
    while(1){
//      left Node
        if(num < temp->data){
           while() 
        }
        else
        {
//      right Node
        }


    }


}
void create_tree(Node **root, int n){
    while(n--){
        Node *new = (Node *)malloc(sizeof(Node ));
        int num;
        scanf("%d", &num);
        //root
        if(*root == NULL){
            *root = new;
            (*root)->data = num;
            (*root)->left = NULL;
            (*root)->right = NULL;
            continue;
        }
        //else 

        

    }
}
void print_tree(Node *root){

}
void destroyTree(Node *root) {
    if(root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif

    int n;
    Node *root = NULL;
    
    scanf("%d",&n);
    
    create_tree(&root, n);
    print_tree(root);
    destroyTree(root);
    

    return 0;
}
