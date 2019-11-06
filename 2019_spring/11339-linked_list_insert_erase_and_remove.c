#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

unsigned int len = 0;

// add node in front of the exist pos_th node!
void do_I(Node **head,size_t pos,unsigned short val) {

    Node *new = (Node *)malloc(sizeof(Node ));

    new->val = val; 
    
    if(len == 0){
//      head
        *head = new;
        
        new->next = NULL;
        new->prev = NULL;
    }else{
            
        Node *temp = *head;
        if(pos >= len) {
//          in this situation, new is the last node 
//          go to the last node first
            while(temp->next != NULL ) temp = temp->next;
   
            new->next = NULL;
            new->prev = temp;
            temp->next = new;
            ++len;
            return;
        }
//      go to the pos_th node
        for(int i = 0; i < pos; ++i) temp = temp->next;
        
        if( temp == (*head) ) {
            new->prev = NULL;
            new->next = *head;
            (*head)->prev = new;
            (*head) = new; 
        } else {
            new->prev = temp->prev;
            new->next = temp;
            temp->prev->next = new;
            temp->prev = new; 
        }
    }
    len++;

}
void do_E(Node **head,size_t begin_pos,size_t end_pos) {
//  limit 
    if(len == 0) return;
    if(end_pos >= len ) end_pos = len;
    if(begin_pos >= len ) begin_pos = len;
    if(begin_pos >= end_pos) return;
        
//  node start is the start node
//  node end is the end node
//  do not delete the end node , delete node in front of it
    Node *start = *head;
    Node *end = *head;
    for(int i = 0; i < begin_pos; ++i) start = start->next;
    for(int i = 0; i < end_pos; ++i) end = end->next;
/*    
    the problem say "If any input positions in the two operations above 
    is greater than or equal to the length of the list, 
    treat the input position as the next position of the last position at the list."

    "treat the input position as the next position of the last position at the list."
    so it is important to think about what if the end node is NULL
*/
    if(start == *head){
        *head = end;
    }else if(end == NULL){
        start->prev->next = NULL;
    }else { 
        start->prev->next = end; 
        end->prev = start->prev;
    }

    len -= (end_pos - begin_pos);
}
void do_P(Node  *head,size_t pos){
    Node *temp = head;
    if(len == 0) return;
    if(pos >= len) pos = len-1;
    for(int i = 0; i < pos; ++i) temp = temp->next;
    if(temp != NULL) printf("%d ", temp->val);
}
void do_R(Node **head, unsigned short val) {
    Node *temp = *head;
    while( temp != NULL ) {
        if( temp->val == val ) {
            Node *d = temp;
            // the left side of the temp
            // if is head
            if(temp == *head) *head = (*head)->next;
            else temp->prev->next = temp->next;
            //if is the last node
            if(temp->next == NULL) ;
            else temp->next->prev = temp->prev;
            
            temp = temp->next;
            free(d);

            --len;
        }else{
            temp = temp->next;
        }
        
    }
}
void do_S(Node  *head) {
    if(head == NULL) return;

    Node *temp = head;
    while( temp != NULL ) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    Node *head=NULL;
	size_t N;
	scanf("%zu",&N);
	while(N--)
	{
        char op;
        unsigned short val;
        size_t pos,begin_pos,end_pos;
        scanf(" %c",&op);
        switch(op)
        {
            case 'I':
                scanf("%zu %hu",&pos,&val);
                do_I(&head,pos,val);
                //printf("I OK!\n");
                //do_S(head);
                //printf("\n");
                break;
            case 'E':
                scanf("%zu %zu",&begin_pos,&end_pos);
                do_E(&head,begin_pos,end_pos);
                //printf("E OK!\n");
                //do_S(head);
                //printf("\n");
                break;
            case 'P':
                scanf("%zu",&pos);
                do_P(head,pos);                
                //printf("P OK!\n");
                //printf("\n");
                break;
            case 'R':
                scanf("%hu",&val);
                do_R(&head,val);
                //printf("R OK!\n");
                //do_S(head);
                //printf("\n");
                break;
            case 'S':
                do_S(head);
                //printf("S OK!\n");
                //printf("\n");
                break;
        }
    }	
        
    return 0;
}
