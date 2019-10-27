#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

unsigned num = 0;

Node* create(int n){
    num = n;
    int total = n+1;
    Node *temp = NULL, *head = NULL;
    head = (Node *)malloc(sizeof(Node ));
    head->data = total-n; n--;
    head->next = NULL;
    temp = head;

    while(n > 0){
        Node *new = (Node *)malloc(sizeof(Node ));
        temp->next = new;
        new->data = total-n; n--;
        new->next = NULL;
        temp = new;
    }
    temp->next = head;

    return head;

}
void josephus(int m, Node *head){
    Node *now = head;
    while(num != 1){
        //find the node before target
        for (int i = 0; i < (m-2) % num; ++i) now = now->next;
        Node *del = now->next;
        printf("%d ", del->data);
        num--;
        now->next = now->next->next;
        now = now->next;
        free(del);
    }
    printf("%d ", now->data);
}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
	int n,m;
	scanf("%u %u",&n, &m);
	josephus(m,create(n));
    
	
	

    return 0;
}
