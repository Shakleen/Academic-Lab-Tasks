#include <stdio.h>
#include <stdlib.h>

struct num{
    int no;
    struct num *next;
};

void enqueue(struct num **head, struct num **tail, int no);
int dequeue (struct num **head);

int main(){
    struct num *head = NULL, *tail = NULL;

    enqueue (&head, &tail, 2);
    enqueue (&head, &tail, 3);
    enqueue (&head, &tail, 4);
    enqueue (&head, &tail, 5);

    struct num *it = head;

    while (it != NULL){
        printf("%d\n", it->no);
        it = it->next;
    }

    printf("dequeue = %d\n", dequeue(&head));

    it = head;
    while (it != NULL){
        printf("%d\n", it->no);
        it = it->next;
    }

    return 0;
}

void enqueue(struct num **head, struct num **tail, int n){
    struct num *cur = (struct num *) malloc (sizeof(struct num));

    if ((*head) == NULL){
        (*head) = cur;
        (*tail) = cur;
    }
    else{
        (*tail) -> next = cur;
        (*tail) = cur;
    }

    cur -> next = NULL;
    cur -> no = n;

    return;
}

int dequeue(struct num **head){
    if ((*head) == NULL){
        return 0;
    }

    int a = (*head) -> no;

    (*head) = (*head) -> next;

    return a;
}
