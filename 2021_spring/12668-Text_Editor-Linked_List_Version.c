#define D
#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    char data;
    struct _Node *prev;
    struct _Node *next;
}Node;
char word[1000005];
char word[1000005];

Node* erase(Node *now);
Node* insert(Node *now,char c);

Node *head;
Node *end;
Node *now;


int main(void){
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif 
    int T,N;
    scanf("%d\n",&T);
    while(T--){
        scanf("%d\n",&N);
        scanf("%s",word);
        //create a head and now

        head=(Node*)malloc(sizeof(Node));
        end=(Node*)malloc(sizeof(Node));

        head->prev = NULL;
        head->next = end;
        head->data = '@';

        end->prev = head;
        end->next = NULL;
        end->data = '%';

        now = end;

        for(int i=0;i<N;i++){
            if(word[i] == 'L'){
                if(now->prev != head){
                    now=now->prev;
                }
            }
            else if(word[i] == 'R'){
                if(now != end){
                    now=now->next;
                }
            }
            else if(word[i] == 'B'){
                now = erase(now);
            }
            else{
                now = insert(now,word[i]);
            }
        }
        now=head->next;
        free(head);
        while(now){
            Node *temp=now;
            if (now != end) printf("%c",now->data);
            now=now->next;
            free(temp);
        }
        free(now);
        printf("\n");
    }
    return 0;
}

Node* erase(Node *now){
    if (now->prev == head) {
        return now;
    } else {
        Node *temp=now->prev;

        temp->prev->next=now;
        now->prev=temp->prev;

        free(temp);
        return now; 
    }





    /*
    if (temp->prev) {
    } else {
        head->next = now;
        now->prev = head;
    }
    free(temp);
    return now;
    */
}

Node* insert(Node *now,char c){
    Node *newnode=(Node*)malloc(sizeof(Node));

    newnode->data=c;
    newnode->prev=now->prev;
    newnode->next=now;

    now->prev->next=newnode;
    now->prev=newnode;
    return now;
}


