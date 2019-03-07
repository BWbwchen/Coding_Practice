// WARNING !!! this code haven't finished !!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
Node *begin = NULL;
Node *ptr = NULL; // prev
Node *tail = NULL;

void do_I(Node **head,size_t pos,unsigned short val) {
    
    if(len == 0){
        *head = (Node *)malloc(sizeof(Node ));
        begin = *head;
        begin->val = val;
        begin->next = NULL;
        begin->prev = NULL;
        ptr = begin;
        
    }else{
        Node *new = (Node *)malloc(sizeof(Node ));
            
        new->val = val;
        new->prev = ptr;
        ptr->next = new;
        new->next = NULL;
        
        if(pos >= len) {
            //tail
            new->next = *head;
        }else{
            new = ptr;
        }
    }
    len++;

}
void do_E(Node **head,size_t begin_pos,size_t end_pos) {
    if(begin_pos >= end_pos) return;
    
    //if over the limit
    if(end_pos >= len) {

    }else{
        Node *start = *head;
        Node *end = *head;
    }
}
void do_P(Node  *head,size_t pos){
    Node *temp = head;
    for(int i = 1; i <= pos && temp->next != NULL; ++i) temp = temp->next;
    printf("%d ", temp->val);
}
void do_R(Node **head,unsigned short val) {
    Node *temp = *head;
    while( temp != NULL ) {
        if( temp->val == val ) {
            Node *d = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp = temp->next;
            free(d);
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
                break;
            case 'E':
                scanf("%zu %zu",&begin_pos,&end_pos);
                do_E(&head,begin_pos,end_pos);
                break;
            case 'P':
                scanf("%zu",&pos);
                do_P(head,pos);                
                break;
            case 'R':
                scanf("%hu",&val);
                do_R(&head,val);
                break;
            case 'S':
                do_S(head);
                break;
        }
    }	
        
    return 0;
}
