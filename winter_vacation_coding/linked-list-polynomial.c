#include <stdio.h>
#include <stdlib.h>

typedef struct a{
	float coef;
	int expo;
	struct a *next;
} Poly;

Poly *new_list = NULL, *tail = NULL;

Poly* input (Poly *head)	{
	float co;
	int ex;
	scanf("%f%d", &co, &ex);

	if(head == NULL){
		head = (Poly *)malloc(sizeof(Poly ));
		head->next = NULL;
		head->coef = co;
		head->expo = ex;
		return head;
	}

	Poly *new = (Poly *)malloc(sizeof(Poly ));
	new->coef = co;
	new->expo = ex;
	new->next = NULL;

	Poly *temp = head;
	while(temp->next != NULL) temp = temp->next;
	temp->next = new;

	return head;
}
void output(Poly *head){
	printf("---------output------------\n");
	
	while(head != NULL){
		
		printf("(%.3fx^%d)", head->coef, head->expo);
		if(head->next != NULL) printf(" + ");
		
		Poly *temp = head;
		head = head->next;
		free(temp);
	}
	printf("\n");
}
void addtoc (float co, int ex){
	if(new_list == NULL){
		new_list = (Poly* )malloc(sizeof(Poly ));
		tail = new_list;
		tail->next = NULL;
		tail->coef = co;
		tail->expo = ex;
		return ;
	}

	Poly *new = (Poly* )malloc(sizeof(Poly ));
	tail->next = new;
	new->next = NULL;
	tail = new;
	tail->next = NULL;
	tail->coef = co;
	tail->expo = ex;
}
void add (Poly *pa, Poly *pb){

	while(pa && pb){
		if(pa->expo > pb->expo){
			addtoc(pa->coef, pa->expo);
			pa = pa->next;
		}else if(pa->expo < pb->expo){
			addtoc(pb->coef, pb->expo);
			pb = pb->next;
		}else if(pa->expo == pb->expo){
			if((pa->coef + pb->coef) != 0){
				addtoc(pa->coef+pb->coef, pa->expo);
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	while(pa){
		addtoc(pa->coef, pa->expo);
		pa = pa->next;
	}
	while(pb){
		addtoc(pb->coef, pb->expo);
		pb = pb->next;
	}
}


int main (int argc, char* argv[]){
	#ifdef DEBUG
	freopen ("test.in", "r", stdin);
	#endif

	
	Poly *a_head = NULL, *b_head = NULL;
	int a_total, b_total;
	scanf("%d%d", &a_total, &b_total);
	while(a_total--) a_head = input(a_head);
	while(b_total--) b_head = input(b_head);

	add(a_head, b_head);

	output(a_head);
	output(b_head);
	output(new_list);

	return 0;
}
