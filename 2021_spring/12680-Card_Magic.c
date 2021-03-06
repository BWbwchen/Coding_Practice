#define DEBUG-
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "function.h"

typedef struct _Node {
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList();
void PrintList(Node*);
void Merge(Node*, int, int);
void Cut(Node*, int, int);

#define __FUNCTION_H__
#ifndef __FUNCTION_H__
int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    Node* dummy_head;
    Node* tail;

    dummy_head = (Node*)malloc(sizeof(Node));
    dummy_head->data = NULL;
    dummy_head->size = -1;

    tail = dummy_head;

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        tail->next = ReadOneList();
        tail = tail->next;
    }
    char act[10];
    int x, y;
    for (int i = 0; i < M; i++) {
        scanf("%s %d %d", act, &x, &y);
        if (act[0] == 'M') {
            Merge(dummy_head, x, y);
        } else {
            Cut(dummy_head, x, y);
        }
    }
    PrintList(dummy_head);
    return 0;
}
#endif

Node* ReadOneLst() {
    int num, i;
    scanf("%d: ", &num);
    Node* now = (Node*)malloc(sizeof(Node));
    // we need to malloc *data array
    now->data = (int*)malloc((num) * sizeof(int));
    now->size = num;
    now->next = NULL;
    for (i = 0; i < num; i++) {
        scanf("%d ", &(now->data[i]));
    }
    return now;
}
void PrintList(Node* start) {
    while (start->next) {
        start = start->next;
        // printf("%d\n",start->size);
        for (int i = 0; i < (start->size); ++i) {
            if (i == start->size - 1) {
                printf("%d", start->data[i]);
            } else {
                printf("%d ", start->data[i]);
            }
        }
        if (start->size != 0) printf("\n");
    }
    return;
}
void Merge(Node* start, int a, int b) {
    Node *now = start, *A = NULL, *B = NULL, *temp;
    int flag = 1;
    /*
    while (now->next && (A == NULL || B == NULL)) {
        now = now->next;
        if (a == 1) {
            A = now;
            temp = start;
        }
        if (flag == a - 1) {
            A = now->next;
            temp = now;
        } else if (flag == b) {
            B = now;
        }
        flag++;
    }
    */

    now = start;
    flag = 1;
    // A, temp
    while (now->next && A == NULL) {
        now = now->next;
        if (flag == a - 1) {
            temp = now;
            A = now->next;
            break;
        } else if (a == 1) {
            A = now;
            temp = start;
        }
        flag++;
    }

    now = start;
    flag = 1;
    // B
    while (now->next && B == NULL) {
        now = now->next;
        if (flag == b) {
            B = now;
            break;
        }
        flag++;
    }

    // merge A to B
    int* newdata = (int*)malloc((A->size + B->size) * sizeof(int));

    for (int i = 0; i < B->size; i++) {
        newdata[i] = B->data[i];
    }
    for (int i = 0; i < A->size; i++) {
        newdata[B->size + i] = A->data[i];
    }
    //free(B->data);
    B->data = newdata;
    B->size = A->size + B->size;

    //free(A->data);
    //free(A);
    // delete A from dummy_list
    if (temp->next->next)
        temp->next = temp->next->next;
    else
        temp->next = NULL;
    return;
}
void Cut(Node* start, int a, int b) {
    Node* now = start;
    int flag = 0;
    /*
    do {
        now = now->next;
        flag++;
    } while (flag != a);
    */

    // find a
    flag = 1;
    now = start;
    while (flag != a) {
        now = now->next;
        flag++;
    }
    now = now->next;

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = (int*)malloc(sizeof(int) * (now->size - b));
    for (int i = b; i < now->size; i++) {
        newnode->data[i - b] = now->data[i];
        // printf("%d?",now->data[i]);
    }
    newnode->size = now->size - b;
    now->size = b;
    // add a node to dummy_list
    Node* temp = now->next;
    now->next = newnode;
    if (temp)
        newnode->next = temp;
    else
        newnode->next = NULL;
}
i
