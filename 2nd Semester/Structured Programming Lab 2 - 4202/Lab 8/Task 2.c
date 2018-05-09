#include <stdio.h>
#include <stdlib.h>

struct num{
    int no;
    struct num *next;
};

struct num* push(struct num *head, int n);
int pop (struct num **head);

int main(){
    struct num *head = NULL;

    head = push (head, 2);
    head = push (head, 3);
    head = push (head, 4);
    head = push (head, 5);

    struct num *it = head;

    while (it != NULL){
        printf("%d\n", it->no);
        it = it->next;
    }

    printf("pop = %d\n", pop(&head));

    printf("\nAfter popping\n");
    it = head;
    while (it != NULL){
        printf("%d\n", it->no);
        it = it->next;
    }

    return 0;
}

struct num* push(struct num *head, int n){
    struct num *cur = (struct num *) malloc (sizeof(struct num)), *it = head;

    cur -> next = NULL;
    cur -> no = n;

    if (head == NULL){
        head = cur;
    }
    else{
        while ((it->next) != NULL){
            it = it->next;
        }

        it -> next = cur;
    }
    return head;
}

int pop(struct num **head){
    int a = 0, f = 0;

    struct num *it = (*head), *prev = NULL;

    while ((it->next) != NULL){
        prev = it;
        it = it->next;
    }

    a = it->no;
    prev -> next = NULL;

    return a;
}
