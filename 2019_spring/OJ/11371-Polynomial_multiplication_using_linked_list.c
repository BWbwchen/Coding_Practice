#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node{
	long data;  //the value of coefficient
	int power; //the value of power
	struct _Node *next;
	struct _Node *prev;
}Node;
void printNode(Node* head){         //the function which will print the output
    Node *temp = head;
    while(temp != NULL){
        printf(" %ld %d", temp->data, temp->power);
        temp = temp->next;
    }
    printf("\n");
}
Node* create(){                     //create polynomial linked list
    Node *head = NULL, *temp = NULL, *now = NULL;
    long coef;
    int expo;
    int state = 1;//1 for go, 0 for end
    while(scanf(" %ld %d", &coef, &expo) == 2 ){
        if(expo == 0) state = 0;
        if(head == NULL){
            head = (Node *)malloc(sizeof(Node ));
            head->data = coef;
            head->power = expo;
            head->next = NULL;
            temp = head;
        }else{
            now = (Node *)malloc(sizeof(Node ));
            temp->next = now;
            now->data = coef;
            now->power = expo;
            now->next = NULL;
            temp = now;
        }
        if(!state) break;
    }
    return head;
}
void destroy(Node *node){           //destroy polynomial linked list
    if(node == NULL) return ;
    Node *now = node;
    destroy(node->next);
    free(now);
}

Node* multiple(Node* p1, Node* p2){ //input two polynomial linked list and return the result

}


int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
	Node *p1=create(); //polynomial linked list1
	Node *p2=create(); //polynomial linked list2
	Node *mul=multiple(p1,p2);
	printNode(mul);
	//printNode(p1);
	//printNode(p2);
	destroy(mul);
	destroy(p2);
	destroy(p1);
    
	
	

    return 0;
}
