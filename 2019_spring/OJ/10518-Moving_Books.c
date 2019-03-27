#define DEBUG
#define MAXN 1000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _Node {
    int index;
    struct _Node *next;
} Node;

Node *head = NULL;
int total_book;

void Build () {
    Node *temp = head;
    int i = 0;
    
    while (i < total_book) {
        Node *new = (Node *)malloc(sizeof(Node ));
        new->index = i++;
        new->next = NULL;
        if(head == NULL){
            head = new;
            temp = head;
        }else{
            temp->next = new;
            temp = new;
        }
    }
}

void move_on (int under, int top) {
    Node *under_Node = head, *top_Node = head;
    Node *pre_under_Node = head;
    
    while (under_Node->index != under) {
        pre_under_Node = under_Node;
        under_Node = under_Node->next;
    }
    while (top_Node->index != top) {
        top_Node = top_Node->next;
    }

    if(under_Node == head) head = under_Node->next;
    else pre_under_Node->next = under_Node->next;
    under_Node->next = top_Node->next;
    top_Node->next = under_Node;

}

void move_under (int top, int under) {
    
    Node *under_Node = head, *top_Node = head;
    Node *pre_under_Node = head, *pre_top_Node = head;
    
    while (top_Node->index != top) {
        pre_top_Node = top_Node;
        top_Node = top_Node->next;
    }
    while (under_Node->index != under) {
        pre_under_Node = under_Node;
        under_Node = under_Node->next;
    }

    if(top_Node == head) head = top_Node->next;
    else pre_top_Node->next = top_Node->next;
    pre_under_Node->next = top_Node;
    top_Node->next = under_Node;
        
}

void remove_Node (int target) {
    Node *pre = head, *del = head;
    while (del->index != target) {
        pre = del;
        del = del->next;
    }
    if (del == head) {
        head = del->next;
    } else {
        pre->next = del->next;
    }
    free(del);
}

void print_list () {
    if(head == NULL || !total_book) return;
    
    Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->index);
        temp = temp->next;
    }
    printf("\n");
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    scanf("%d", &total_book);
    
    Build();

    char move[MAXN], on_or_down[10];
    while ( 1 ) {
        int a, b;
        scanf(" %s", move);
        if (strcmp(move, "move") == 0) {
            
            scanf("%d %s %d", &a, on_or_down, &b);
            
            if (a == b) continue;
            if (a >= total_book || b >= total_book) continue;

            if (strcmp(on_or_down, "on") == 0) move_on(a, b);
            else if (strcmp(on_or_down, "under") == 0) move_under(a, b);
            else ;

            //print_list();

        } else if (strcmp(move, "remove") == 0) {
            scanf("%d", &a);
            remove_Node(a);
            //print_list();

        } else if (strcmp(move, "exit") == 0) {
            print_list();
            break;
        }
    }
    
    
    

    return 0;
}

