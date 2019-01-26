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
//			done
			printf("(%d", coin[0]);
			for(i = 1; i < value_number; i++) printf(",%d", coin[i]);
			printf(")\n");
			return ;
		}else if(smallest_value == value_number){
			return;
		}else{
//		dfs	
			dfs(total, smallest_value+1);
			coin[smallest_value]++;
			dfs(total-value[smallest_value], smallest_value);
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
	
	//dfs
	dfs(amount, 0);
	
	return 0;
}
