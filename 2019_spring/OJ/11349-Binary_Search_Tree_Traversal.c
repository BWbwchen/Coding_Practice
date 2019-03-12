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

void create_tree(Node **root, int n){
    Node *new = (Node *)malloc(sizeof(Node ));
    
    int num ;
    scanf("%d", &num);
    
    if(*root == NULL) {

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
