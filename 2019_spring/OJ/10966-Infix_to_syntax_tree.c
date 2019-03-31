#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);



int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }
    
	
	

    return 0;
}

BTNode* EXPR()
{

    char c;
    BTNode *father = NULL, *right = NULL;
    
    if (pos >= 0) {
        right = FACTOR();
        c = expr[pos];
        if (pos > 0) {
            if(c == '&' || c == '|') {
                father = makeNode(c);
                father->right = right;
                pos--;
                father->left = EXPR();
            } else father = right; 
        } else father = right;
    }

    return father;

}
BTNode* FACTOR()
{
    char c;
    BTNode *node = NULL;

    if (pos >= 0) {
        c = expr[pos--];
        if ('A' <= c && c <= 'D') {
            node = makeNode (c);
        } else
        if (c == ')') {
            node = EXPR();
            if(expr[pos--] != '(' ) {
                printf("ERROR parenthesis!!\n");
            }
        }
    }

    return node;

}
BTNode* makeNode(char c)
{
    BTNode* new = (BTNode* )malloc(sizeof(BTNode));
    new->right = NULL; new->left = NULL;
    for (int i = 0; i < NUMSYM; ++i)
        if (c == sym[i]) new->data = i;
    return new;
}


/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
