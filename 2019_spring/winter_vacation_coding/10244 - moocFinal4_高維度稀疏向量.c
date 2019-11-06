#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXN 4000000

int vec1[MAXN][2];
int vec2[MAXN][2];



int main(int argc, char const *argv[]){
    #ifdef LOCAL
    freopen ("text.in" , "r" , stdin);
    freopen ("text.out" , "w" , stdout);
    #endif
    int v1 = 1, v2 = 1;
    while(scanf("%d:%d ", &vec1[v1][0], &vec1[v1][1]) == 2 && vec1[v1][0] != 0) v1++;
    while(scanf("%d:%d ", &vec2[v2][0], &vec2[v2][1]) == 2 && vec2[v2][0] != 0) v2++;

    long long ans = 0;
    //for every element in vec1 find the correspond dimension in vec2
    //if dimension match , dot !
    for(int i = 1; i < v1; i++)
    {
        for(int j = 1; j < v2; j++)
        {
            if(vec1[i][0] == vec2[j][0]){
                ans += vec1[i][1] * vec2[j][1];
                break;
            }else if(vec1[i][0] < vec2[j][0]){
                break;
            } 
        }
    }
    printf("%lld\n", ans);

    

    return 0;
}
