/*

	Queue by C

	Functions:
	(1) Push() or Enqueue
	(2) Pop() or dequeue
	(5) IsEmpty()

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct a{
	int data;
	struct a *next;
} Queue;

Queue *front = NULL, *rear = NULL;

int IsEmpty (){
	//either front or rear can't be NULL if the queue isn't empty !
	return ( ( front && rear ) == 0);
}
void Push (int x){
	if(IsEmpty()){
		front = (Queue* )malloc(sizeof(Queue ));
		rear = front;
		rear->data = x;
		rear->next = NULL;
		return;
	}

	Queue *new = (Queue* )malloc(sizeof(Queue ));
	rear->next = new;
	rear = new;
	rear->data = x;
	rear->next = NULL;
}
void Pop(){
	if(IsEmpty()){
		printf("No item!\n");
		return;
	}
	
	
	printf("Data : %d\n", front->data);
	Queue *temp = front;
	front = front->next;
	free(temp);
}

int main (int argc, char* argv[]){
	#ifdef DEBUG
	freopen ("test.in", "r", stdin);
	#endif

	
//	push 1~10
	int i;
	for(i = 1; i <= 10; ++i) Push(i);

	printf("IsEmpty ? : %d\n", IsEmpty());

//	pop 4 Items
	for(i = 1; i <=4; ++i) Pop();

	printf("IsEmpty ? : %d\n", IsEmpty());

//	pop all 
 	for(; !IsEmpty();) Pop();

	printf("IsEmpty ? : %d\n", IsEmpty());

	return 0;
}
