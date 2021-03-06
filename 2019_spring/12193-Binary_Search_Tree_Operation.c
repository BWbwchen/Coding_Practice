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
int sum = 0;

int travel (Node **head, int target) 
{
    if (target < (*head)->data) {
        if ((*head)->left == NULL) return LEFT;
        else { 
            *head = (*head)->left;
            return travel( head, target);
        }
    } else
    if ((*head)->data < target) {
        if ((*head)->right == NULL) return RIGHT;
        else { 
            *head = (*head)->right;
            return travel( head, target);
        }
    } else return -1;
}

void BuildTree (Node **head, int total) 
{
    while (total--) {
        Node *new = (Node *)malloc(sizeof(Node ));
        scanf("%d", &new->data);
        new->right = NULL; new->left = NULL;

        if (*head == NULL) *head = new;
        else {
            Node *father = *head;
            int dir = RIGHT;
            dir = travel (&father, new->data);

            if (dir == RIGHT) {
                father->right = new;
            } else 
            if (dir == LEFT) {
                father->left = new;
            }
        }

    }
}

int GetMax (Node *head)
{
    if (head == NULL) return 0;
    if (head->left == NULL && head->right == NULL) return 1;
    
    int left = 0, right = 0;
    left = GetMax(head->left);
    right = GetMax(head->right);

    if (left > right) return left+1;
    else return right+1;
}

int SumLevel (Node *root, int level)
{
    if (root == NULL) return 0;
    if (level == 1) { 
        sum++; 
        return root->data;
    }
    return SumLevel(root->left, level-1) + SumLevel(root->right, level-1);
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
    BuildTree(&root, total_Node);
    
    scanf("%d", &num);

    while (num--) {
        scanf(" %s",  command);
        int level;

        if (command[0] == 'P') {
            if (root == NULL) printf("NULL");
            else printTree(root); 
            printf("\n");
        } else 
        if (command[0] == 'G') {
            printf("%d\n", GetMax(root));
        }else
        if (command[0] == 'S') {
            scanf(" %d", &level);
            if (level <= 0 || level > GetMax(root)) printf("0\n");
            else printf("%d\n", SumLevel(root, level));
        } else
        if (command[0] == 'A') {
            scanf(" %d", &level);
            if (level <= 0 || level > GetMax(root)) {
                printf("0\n");
                continue;
            }

            sum = 0;
            double ans = (double)SumLevel(root, level);
            ans /= (double)sum;
            printf("%.3f\n", ans);
        }
    }

	
	

    return 0;
}
