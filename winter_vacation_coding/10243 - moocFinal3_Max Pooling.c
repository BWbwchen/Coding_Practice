#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXN 1010

int map[MAXN][MAXN];
int n;

int max_in_3 (int row, int col){
    int max = -MAXN;
    for(int i = row; i < row+3; i++)
    {
        for(int j = col; j < col+3; j++)
        {
            if(map[i][j] > max) max = map[i][j];
        }
    }
    
    return max;
}

int main(int argc, char const *argv[]){
    #ifdef LOCAL
    freopen ("text.in" , "r" , stdin);
    freopen ("text.out" , "w" , stdout);
    #endif
    //input 
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
        
    }
    //find max
    for(int i = 0; i < n-2; i++)
    {
        for(int j = 0; j < n-2; j++)
        {
			printf("%d", max_in_3(i,j));
            if(j != n-3) printf(" ");
        }
        printf("\n");
    }
    

    

    return 0;
}
