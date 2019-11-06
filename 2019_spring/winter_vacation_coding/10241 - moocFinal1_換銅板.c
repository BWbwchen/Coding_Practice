#define LOCAL
#include <stdio.h>
#define MAXN 10

int value_number;
int value[MAXN];
int coin[MAXN];

void dfs (int total, int smallest_value){
	int i;
	if(total >= 0){
		if(total == 0){
//			done!
			printf("(%d", coin[0]);
			for(i = 1; i < value_number; i++) printf(",%d", coin[i]);
			printf(")\n");
			return ;
		}else if(smallest_value == value_number){
			return;
		}else{
//			dfs
//			think:
//			we have 2 strategy
//			1. not to use value[smallest_value] coin
//			or 2. use 1 coin

//			not to use :				
			dfs(total, smallest_value+1);
//			use 1 coin
			coin[smallest_value]++;
			dfs(total-value[smallest_value], smallest_value);
//			remember to take back !
			coin[smallest_value]--;
		}
	}
}

int main(){
	#ifdef LOCAL
	freopen ("in.in", "r", stdin);
	#endif
	//input
	int amount, i;
	scanf("%d", &value_number);
	for(i = 0; i < value_number; i++) scanf("%d", &value[i]);
	scanf("%d", &amount);
	
//	dfs
//	if you call this function, it will print out all the possible solutionbase on the smallest_value
//	example:
//	dfs(amount, 2) and value_number is 5
//	dfs() will print out the solution that will use coin its value is value[2]~value[4]
	dfs(amount, 0);
	
	return 0;
}
