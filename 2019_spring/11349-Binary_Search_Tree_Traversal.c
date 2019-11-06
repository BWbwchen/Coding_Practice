#define DEBUG
#define LEFT 1
#define RIGHT 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;
int total = 0;
int travel(Node **temp, int goal){
    Node *ptr = *temp;
    
    if(goal < ptr->data){
        if( (*temp)->left == NULL) {
            return LEFT; 
        }else{
            (*temp) = (*temp)->left;
            return travel(temp, goal);
        }
    }else if(ptr->data < goal){
        if ( (*temp)->right == NULL){ 
            return RIGHT;
        }else{
            (*temp) = (*temp)->right;
            return travel( temp , goal);
        }
    }
}

void create_tree(Node **root, int n){
    total = n;
    while(n--){
        Node *new = (Node *)malloc(sizeof(Node ));
        int num;
        scanf("%d", &num);
        //root
        if(*root == NULL){
            *root = new;
            (*root)->data = num;
            (*root)->left = NULL; (*root)->right = NULL;
            continue;
        }
        //else 
        else{
            Node *temp = *root;
            int dir = 0;
            new->data = num;
            new->left = NULL; new->right = NULL;
            
            dir = travel(&temp, num);
            
            if(dir == LEFT){
                temp->left = new;
            }else if (dir == RIGHT){
                temp->right = new;
            }else {
                total--;
            }
        }
    }
}
void preorder(Node *root){
    if(root == NULL) return ;
    printf("%d", root->data); total--;
    if(total != 0) printf(" ");

    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root){
    if(root == NULL) return ;
    inorder(root->left);
    printf("%d", root->data); total--;
    if(total != 0) printf(" ");

    inorder(root->right);
}
void postorder(Node *root){
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data); total--;
    if(total != 0) printf(" ");
    
}
void print_tree(Node *root){
    int temp = total;
    printf("preorder: ");
    preorder(root);
    printf("\n");
    total = temp;
    printf("inorder: ");
    inorder(root);
    printf("\n");
    total = temp;
    printf("postorder: ");
    postorder(root);
    printf("\n");


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
