#define DEBUG
#define MAXN 1010
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head)
{
    char c = getchar();

    (*head) = (Node *)malloc(sizeof(Node ));
    (*head)->data = c;
    (*head)->right = NULL; (*head)->left = NULL; 

    if ('A' <= c && c <= 'D') {
        
    } else 
    if (c == '|' || c == '&') {
        constructTree(&(*head)->left);
        constructTree(&(*head)->right);
    }

}
void printInfix(Node *root);
void freeTree(Node *root);

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    int n;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        getchar();
        Node *root=NULL;
        constructTree(&root);// you have to implement this function
        printInfix(root);//output function 
        printf("\n");
        freeTree(root);
        n--;

    }
    
    

    return 0;
}

void printInfix(Node *root){
    if (root != NULL) {
        printInfix(root->left);

        printf("%c", root->data);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf("(");

        printInfix(root->right);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf(")");
    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
