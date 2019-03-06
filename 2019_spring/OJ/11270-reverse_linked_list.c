#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node *head = NULL;
Node *temp;
int data;

Node* createList() {
    while(scanf("%d", &data) == 1 && data != -1){
        if(head == NULL){
            head = (Node *)malloc(sizeof(Node ));
            head->data = data;
            head->next = NULL;
            temp = head;
            
        }else{
            Node *new = (Node *)malloc(sizeof(Node ));
            new->data = data;
            new->next = NULL;
            temp->next = new;
            temp = new; 
        }
    }
    return head;
}
Node* reverse(Node* heada) {
    if(heada != NULL){
        Node *pre = NULL;
        Node *mid = heada;
        Node *nex = mid->next;
        
        while(nex != NULL){
            mid->next = pre;
            pre = mid;
            mid = nex;
            nex = nex->next;
        }
        
        mid->next = pre;
        return mid;
    }else{
        return NULL;
    }
    
}


void printList(Node *head);
void freeList(Node*);

int main(int argc, char *argv[]){
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif



    head = createList();
	head = reverse(head);
	printList(head);
	freeList(head);


    
    
    return 0;
}

void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
