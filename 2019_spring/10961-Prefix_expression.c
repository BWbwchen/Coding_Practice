#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
    the key is this form
    + (A) (B)
    
    where A and B can be any form such like a expression
    or number or symbol(+, -)

    and "ungetc" you should google it:)
*/

int prefix(){
    char c;
    c = getchar();
    int A = 0, B = 0, ans = 0;
    
    if(c == '+'){
        A = prefix();
        B = prefix();
        ans = A+B;
    }else if(c == '-'){
        A = prefix();
        B = prefix();
        ans = A - B;
    }else if(isdigit(c)){
        ungetc(c, stdin);
        scanf("%d", &ans);
        return ans;
    }else if(isspace(c)){
        return prefix();
    }


    return ans;
}

int main() {
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    printf("%d\n", prefix());

    return 0;
}
