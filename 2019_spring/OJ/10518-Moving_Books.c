#define DEBUG
#define MAXN 10500
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _Node {
    int index;
    struct _Node *pre;
    struct _Node *next;
} Node;

Node *head = NULL;
int total_book;

int existNode[MAXN] = {[0 ... MAXN-1] = 1};

void Build () {
    Node *temp = NULL;
    int i = 0;
    // 1 for book exist
    head = (Node *)malloc(sizeof(Node ));
    head->index = i++;
    head->pre = NULL;
    head->next = NULL;
    temp = head;

    while (i < total_book) {
        Node *new = (Node *)malloc(sizeof(Node ));
        new->index = i++;
        new->next = NULL;
        temp->next = new;
        new->pre = temp;
        temp = new;
    }
}

void move_on (int under, int top) {
    // underNode point to the *address*
    // of what we will do something on it

    Node *underNode = head, *topNode = head;
    // Walk the list to find the Nodeo
    while (underNode->index != under) underNode = underNode->next;
    while (topNode->index != top) topNode = topNode->next;

    if (underNode == head) {
        head = underNode->next;
    } else {
        underNode->pre->next = underNode->next;   
    }


    //underNode->pre->next = underNode->next;
    underNode->next->pre = underNode->pre;

    underNode->pre = topNode;
    underNode->next = topNode->next;

    if (topNode->next == NULL) {
        
    } else {
        topNode->next->pre = underNode;
    }
    //topNode->next->prev = underNode;
    topNode->next = underNode;



}

void move_under (int under, int top) {
    // topNode point to the *address*
    // of what we will do something on it
    
    
    Node *underNode = head, *topNode = head;
    // Walk the list to find the Nodeo
    while (underNode->index != under) underNode = underNode->next;
    while (topNode->index != top) topNode = topNode->next;
    

    if (underNode == head) {
        head = underNode->next;
    } else {
        underNode->pre->next = underNode->next;   
    }

    if (underNode->next == NULL) {
         
    } else {
        underNode->next->pre = underNode->pre;
    }

    //underNode->pre->next = underNode->next;
    //underNode->next->pre = underNode->pre;

    if (topNode == head) {
        head = underNode;
    } else {
        topNode->pre->next = underNode;
    }
    
    //topNode->pre->next = underNode;
    underNode->pre = topNode->pre;


    topNode->pre = underNode;
    underNode->next = topNode;

}

void remove_Node (int target) {
    
    Node *indirect = head;
    while (indirect->index != target) indirect = indirect->next;
    Node *del = indirect;
    if (indirect == head) {
        head = indirect->next;
    } else {
        indirect->pre->next = indirect->next;
    }
    existNode[target] = 0;
    free(del);
    
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
        int a, b, re;
        re = scanf(" %s", move);
        if (re == EOF) {
            print_list();
            break;
        }
        if (move[0] == 'm') {
            
            scanf("%d %s %d", &a, on_or_down, &b);
            
            if (a == b) continue;
            if (a >= total_book || b >= total_book) continue;

            if (on_or_down[0] == 'o' && existNode[a] && existNode[b]) move_on(a, b);
            else if (on_or_down[0] == 'u' && existNode[a] && existNode[b]) move_under(a, b);
            else ;

            //print_list();

        } else if (move[0] == 'r') {
            
            scanf("%d", &a);
            if(a < total_book && existNode[a]) remove_Node(a);
            else continue;
            //print_list();

        } else if (move[0] == 'e') {
            print_list();
            break;
        }
    }
    
    
    

    return 0;
}

