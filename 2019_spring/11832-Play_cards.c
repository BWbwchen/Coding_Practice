//WARNING!!!! this code haven't finished !!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!1
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int len = 0;
Node *head = NULL;

void create (int total) {
    int num;
    Node *temp = NULL;
    Node *new = NULL;

    while(total--) {
        scanf("%d", &num);
        new = (Node *)malloc(sizeof(Node ));
        new->data = num;
        if(head == NULL){
            head = new;
            head->next = NULL;
            temp = head;
        }else{            
            temp->next = new;
            new->next = NULL;
            temp = new;
        }
    }
    
}

void ADD(int x, int y) {
    Node *new = (Node *)malloc(sizeof(Node ));
//  head
    if(x == 0) {
        new->data = y;
        new->next = head;
        head = new;
    }else{
        Node *temp = head;
        
        while(x-- > 1) temp = temp->next;
        
        new->data = y;
        new->next = temp->next;
        temp->next = new;
    }

}

void CUT(int begin, int end) {
    int idx = 0;
    Node *temp = head;
    Node *new_head = head;
    Node *end_Node = NULL;
//  let temp be the previous Node of the begin Node
    while(idx != begin) {
        if(idx == begin-1) {
            new_head = temp->next;
            end_Node = new_head;
        }else {
            temp=temp->next;
        }
        idx++;
    }
//  find the the previous Node of the end_Node
    for (int i = begin; i < begin+end-1; ++i){
        end_Node = end_Node->next;
    }
    
    temp->next = end_Node->next;
    end_Node->next = head;
    head = new_head;
}

void printNode () {
    Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);

    create(n);

    char buf[5];
    
    while(m--) {
        int x, y;
        scanf("%s", buf);
        scanf("%d%d", &x, &y);
        if(buf[0] == 'A'){
//      ADD
            ADD(x, y);
//          printf("ADD\n");
//          printNode();
        }else {
//      CUT
            CUT(x, y);
//          printf("cut\n");
//          printNode();
        }
    }

    printNode();

    return 0;
}
