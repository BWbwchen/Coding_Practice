#define DEBUG
#define MAXN 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char expr[MAXN];
int pos = 0;

typedef struct _Node{
    char ch;
    struct _Node *left;
    struct _Node *right;
}Node;

int cal(int A, int B, int C, int D){
    int ans = 0, ex1 = 0, ex2 = 0;
    if(pos < strlen(expr)){
        char c = expr[pos++];
     
        if(c == '|'){
            ex1 = cal(A, B, C, D);
            ex2 = cal(A, B, C, D);
            ans = (ex1 | ex2);
        }else if(c == '&'){
            ex1 = cal(A, B, C, D);
            ex2 = cal(A, B, C, D);
            ans = (ex1 & ex2);
        }else if('A' <= c && c <= 'D'){
            switch (c-'A'){
                case 0:
                    return A;
                case 1:
                    return B;
                case 2:
                    return C;
                case 3:
                    return D;
                default:
                    return 0;
            }
        }
        return ans;
    }
}

void print (Node *head){
    if(head == NULL) return ;
    print(head->left);
    printf("%c ", head->ch);
    print(head->right);

}

int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    fgets(expr, MAXN-1, stdin);

    for(int A = 0; A < 2; ++A){
        for(int B = 0; B < 2; ++B){
            for (int C = 0; C < 2; ++C){
                for (int D = 0; D < 2; ++D){
                    pos = 0;
                    printf("%d %d %d %d %d\n", A, B, C, D, cal(A, B, C, D));
                }
            }
        }
    }




    return 0;
}
