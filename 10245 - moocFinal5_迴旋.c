#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXN 1010

int row, col, num;
int i = 1, j = 0;//start from this point !!!
int temp = 1;//what number i put in the map
int map[MAXN][MAXN];

int main(int argc, char const *argv[]){
    #ifdef LOCAL
    freopen ("text.in" , "r" , stdin);
    freopen ("text.out" , "w" , stdout);
    #endif
    scanf("%d%d%d", &row, &col, &num);
    while(temp <= row*col){//think about row = 1, col = 1, num = 1
        //right
        //if the index didn't outside the edge and the next place haven't been filled 
        while(j < col && !map[i][j+1] ){
            map[i][++j] = temp++;
        }
        //down
        //if the index didn't outside the edge and the next place haven't been filled 
        while(i < row && !map[i+1][j] ){
            map[++i][j] = temp++;
        }
        //left
        //if the index didn't outside the edge and the next place haven't been filled 
        while(j > 1 && !map[i][j-1] ){
            map[i][--j] = temp++;
        }
        //up
        //if the index didn't outside the edge and the next place haven't been filled 
        while(i > 1 && !map[i-1][j] ){
            map[--i][j] = temp++;
        }
    }

    for(i = 1; i <= row ; i++){
        for(j = 1; j <= col; j++){
            if(map[i][j] == num){
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    return 0;
}
