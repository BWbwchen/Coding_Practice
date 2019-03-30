#define DEBUG
#define MAXN 1010
#define RIGHT 0
#define LEFT 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _Node {
    int data;
    struct _Node *left;
    struct _Node *right;
}Node;

int buf[MAXN];

int travel (Node **head, int target) 
{
    if (target < (*head)->data) {
        if ((*head)->left == NULL) return LEFT;
        else { 
            *head = (*head)->left;
            return travel( head, target);
        }
    }else
    if ((*head)->data < target) {
        if ((*head)->right == NULL) return RIGHT;
        else { 
            *head = (*head)->right;
            return travel( head, target);
        }
    }
}

Node* BuildTree (Node *head, int total) 
{
    static int index = 0;
    if(index == total) return NULL;

    Node *root = (Node *)malloc(sizeof(Node ));
    root->data = buf[index++];
    
    Node *father = head;
    int dir = RIGHT;
    dir = travel(&father, root->data);

    if (dir == RIGHT) {
        root->right = BuildTree(root, total);
    }else
    if (dir == LEFT) {
        root->left = BuildTree(root, total);
    }

    return root;


}

int GetMax (Node *head)
{
    if (head->left == NULL &7 head->right) return 1;
    
    int left = 0, right = 0;
    left = GetMax(head->left);
    right = GetMax(head->right);

    if (left > right) return left+1;
    else return right+1;
}

void printTree (Node *head) 
{
    if (head == NULL) return;
    printTree(head->left);
    printf("%d ", head->data);
    printTree(head->right);
}

int main ()
{
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    Node *root = NULL;
    int total_Node, num;
    char command[MAXN];

    scanf("%d", &total_Node);
    for (int i = 0; i < total_Node; ++i) scanf("%d", &buf[i]);
    root = BuildTree(root, total_Node);
    scanf("%d", &num);

    while (num--) {
        scanf(" %s",  command);

        if (command[0] == 'P') {
            if (root == NULL) printf("NULL\n");
            else printTree(root);
        }
        else if (command[0] == 'G') {
            printf("%d\n", GetMax(root));
        }
        else if (command[0] == 'S') {
            SumLevel(root);
        }
        else if (command[0] == 'A') {
            AverLevel(root);
        }
    }

	
	

    return 0;
}
