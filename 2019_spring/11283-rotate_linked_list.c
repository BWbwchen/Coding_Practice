#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void rotateList(Node **head, int total);
void freeList(Node *head);
Node* createList();
void printList(Node *head);


void rotateList(Node** head,int total){
    Node *temp = *head;
    Node *tail = *head;

    while(tail->next != NULL) tail = tail->next;
    for(int i = 1; i <= total-1; ++i) temp = temp->next;
    
    tail->next = *head;
    *head = temp->next ;
    temp->next = NULL;
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

Node* createList(){
    Node* head = NULL;
    Node* temp = NULL;
    int data;

    while(1){
        scanf("%d",&data);
        if(data>-1){
            if (temp==NULL) {
                temp = (Node*) malloc(sizeof(Node));
                head = temp;
            } else {
                temp->next = (Node*) malloc(sizeof(Node));
                temp = temp->next;
            }
            temp->data = data;
            temp->next = NULL;
        } else break;
    }
    return head;
}

void printList(Node *head)
{
	Node *temp=head;
	printf("%d", temp->data);
	temp=temp->next;
	
	for(; temp!=NULL; temp=temp->next)
	{
		printf(" %d", temp->data);
	}
	printf("\n");
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    
	Node *head = NULL;
	Node *temp;
	int data;
	int k;

    head = createList();
    scanf("%d",&k);	
    rotateList(&head,k);
    printList(head);
    freeList(head);
	

    return 0;
}
