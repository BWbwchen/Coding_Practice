#define LOCAL
#include <stdio.h>
#define MAXN 10
#define Q 0
#define C 1

int m,n;
int count = 0;
int castle[MAXN] ;//castle[col] = row
int queen[MAXN] ;// queen[col] = row

int check(int row, int col, int type){
	for(int i = 0; i < col; i++){
//  if I haven't put queen            
        if(queen[i] == -1){
            if(castle[i] == row ) return 0;
//  but what if the queen we put will attack the castle that we had put ?
            if(type == Q){
                if(row-castle[i] == i-col || row-castle[i] == col-i) return 0;
            }
        }else{
            if(queen[i] == row || row-queen[i] == i-col || row-queen[i] == col-i) return 0;
        }            
    }
	return 1;
}

void dfs(int col, int qu, int ca){//qu = remain queen , ca = remain castle
    if(col == m+n){
//	done 
		count++;
        return;
	}
    
//	dfs
	for(int i = 0; i < m+n; i++){//for every row
//	try put queen first
		if(check(i, col, Q) && qu){
			queen[col] = i;
			dfs(col+1, qu-1, ca);
//	take back
			queen[col] = -1;
		}

//	try put castle
		if(check(i, col, C) && ca){
			castle[col] = i;
			dfs(col+1, qu, ca-1);
//	take back
			castle[col] = -1;
		}
	
	}

}

int main(){
	#ifdef LOCAL
	freopen ("text.in", "r", stdin);
    freopen ("text.out", "w", stdout);
	#endif
//	input
	scanf("%d%d", &m, &n);

//  initialize
    for(int i = 0; i < MAXN; i++){
        queen[i] = -1;
        castle[i] = -1;
    }

//	dfs
	dfs(0, m, n);
	
	printf("%d\n", count);

	return 0;
}
