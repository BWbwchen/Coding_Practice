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
    // underNode point to the *address*
    // which we will do something on it

    Node **underNode = &head, **topNode = &head;
    Node *moveNode = NULL;

    // Walk the list to find the Node

    while ((*underNode)->index != under)
        underNode = &(*underNode)->next;
    while ((*topNode)->index != top)
        topNode = &(*topNode)->next;
    
    //copy moveNode first
    moveNode = *underNode;
    //update the underNode to the next
    *underNode = (*underNode)->next;
    //the next of moveNode is the next of topNode
    moveNode->next = (*topNode)->next;
    //update the topNode
    (*topNode)->next = moveNode;
}

void move_under (int top, int under) {

    Node **underNode = &head, **topNode = &head;
    Node *moveNode = NULL;

    while ((*underNode)->index != under)
        underNode = &(*underNode)->next;
    while ((*topNode)->index != top)
        topNode = &(*topNode)->next;

    moveNode = *topNode;
    *topNode = (*topNode)->next;
    moveNode->next = *underNode;
    *underNode = moveNode;
}

void remove_Node (int target) {
    
    Node **indirect = &head;

    while ( (*indirect)->index != target ) 
        indirect = &(*indirect)->next;

    *indirect = (*indirect)->next;
    
}

void print_list () {
    
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

