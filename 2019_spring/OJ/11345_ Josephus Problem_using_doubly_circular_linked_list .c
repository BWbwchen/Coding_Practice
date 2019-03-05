#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct man {
    int id;
    struct man* next;
    struct man* prev;
} man;

man* head = NULL;
int count = 0;
int dir = 1;
man *begin = NULL;

man* createList(int n) {
//  remember to initial
    count = n;
    dir = 1;
    man *temp = NULL;
//  head 
    head = (man *)malloc (sizeof(man ));
    head->id = 1;
    head->next = NULL;
    head->prev = NULL;
    temp = head;
//  remain
    for(int i = 2; i <= n; ++i) {
        man *new = (man *)malloc (sizeof(man ));
        
        new->id = i;
        temp->next = new;
        new->prev = temp;

        if(i != n) {
            temp = new;
        }else {
//          make a circle
            head->prev = new;
            new->next = head;
        } 
    }
    return head;
}
// see circle
void debug(int n){
    man *new = head;
    printf("next:\n");
    for(int i = 1; i <= n; ++i) {
        printf("%d->", new->id);
        new = new->next;
    }
    new = head;
    printf("prev:\n");
    for(int i = 1; i <= n; ++i) {
        printf("%d->", new->id);
        new = new->prev;
    }
}

int solveJosephus(int step) {
//  count
    begin = head;
    if(begin == NULL) return 0;
    
    while(count-- > 1){
//      find target(begin) 
//      notice how to count
        for(int i = 0; i < step-1; ++i){
            if(dir == 1){
                begin = begin->next;
            }else{
                begin = begin->prev;
            }
        }

//      delete man
        begin->prev->next = begin->next;
        begin->next->prev = begin->prev;
        //printf("kill %d\n", begin->id);
        
        man *d = begin;
        
        if(dir == 1) begin = begin->prev;
        else begin = begin->next;

        dir = -dir;

        free(d);
    }
    return begin->id;
}


int main (){
    #ifdef DEBUG
    freopen("text.in", "r", stdin);
    #endif
    
    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus(m));
        //debug(n);
    }


    return 0;
}