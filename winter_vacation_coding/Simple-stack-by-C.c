/*

	Stack by C

	Functions:
	(1) Push()
	(2) Pop()
	(3) TopItem()
	(4) IsEmpty()

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct a{
	int data;
	struct a *next;
} Stack;

Stack* push (Stack *now_head, int x){
//	the first case	
	if(now_head == NULL){
		now_head = (Stack *)malloc(sizeof(Stack ));
		now_head->data = x;
		now_head->next = NULL;
		return now_head;
	}
//else case
	Stack *new = (Stack *)malloc(sizeof(Stack ));
	new->data = x;
	new->next = now_head;
	now_head = new;
	return now_head;
}

int IsEmpty (Stack *now_head){
	if( now_head == NULL) return 1;
	else return 0;
}

void Pop(Stack **now_head){
	if(*now_head == NULL){
		printf("No item!\n");
		return;
	}

	printf("Item : %d\n", (*now_head)->data);
	Stack *temp = *now_head;
	(*now_head) = (*now_head)->next;
	free(temp);
}

int TopItem (Stack *now_head){
	if(now_head == NULL){
		return -1;//No item
	}else{
		return now_head->data;
	}
}

int main (int argc, char* argv[]){
	#ifdef DEBUG
	freopen ("test.in", "r", stdin);
	#endif

	Stack *head = NULL;

	
	printf("Isempty ? : %d\n", IsEmpty(head));
	printf("TopItem ? : %d\n", TopItem(head));

//	push 1~10
	int i;
	for(i = 0; i < 11; ++i) head = push(head, i);

	printf("TopItem ? : %d\n", TopItem(head));
	printf("Isempty ? : %d\n", IsEmpty(head));

//	pop 4 items
	for(i = 0; i < 4; ++i) Pop(&head);

	printf("TopItem ? : %d\n", TopItem(head));
	printf("Isempty ? : %d\n", IsEmpty(head));

//	pop all
	for(; !IsEmpty( head );) Pop(&head);

	printf("Isempty ? : %d\n", IsEmpty(head));


	return 0;
}
