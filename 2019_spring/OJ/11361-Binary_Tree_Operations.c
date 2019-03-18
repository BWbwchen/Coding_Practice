//WARNING !!!!!this code hasn't finished yet!!!!!
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

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){

}
void showPostorder(Node* root){
    if(root == NULL) return ;
    showPostorder(root->left);
    showPostorder(root->right);
    printf("%d ", root->data);
}

void freeTree(Node *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif

    int i,n;
    int *inorder,*preorder;
    scanf("%d",&n); // n : the size of binary tree
    /*------------Parse the input----------------*/
    inorder = (int *) malloc(n * sizeof(int));
    preorder = (int *) malloc(n * sizeof(int));
    for(i=0; i<n; i++) scanf("%d", &inorder[i]);
    for(i=0; i<n; i++) scanf("%d", &preorder[i]);
    /*------------Build the binary tree----------*/
    Node *root = buildTree(inorder, preorder,0,n-1);
    /*------------Print out the tree ------------*/
    showPostorder(root);
    freeTree(root);
    free(inorder);
    free(preorder);
    
    

    return 0;
}
