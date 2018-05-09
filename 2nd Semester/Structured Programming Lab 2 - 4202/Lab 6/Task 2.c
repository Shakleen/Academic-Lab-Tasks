#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct num{
    int no;
    struct num* next;
    struct num *prev;
};

int main(){
    struct num *head = NULL, *it = NULL, *jt = NULL, *previous = NULL;
    int no = 0, i = 0, j = 0, k = 0;

    printf("Enter how many elements:\n");

    scanf("%d", &no);

    printf("Enter elements:\n");

    for (i = 0; i < no; i++){
        struct num *cur = (struct num*) malloc(sizeof(struct num));

        scanf("%d", &j);

        cur -> no = j;

        if (i == 0){
            head = cur;
            cur -> next = NULL;
            previous = cur;
            cur -> prev = NULL;
        }
        else{
            cur -> prev = previous;
            previous -> next = cur;
            cur -> next = NULL;
            previous = cur;
        }
    }


    jt = head;

    for (it = jt->next; it != NULL; it = it->next){
        int key = it -> no;

        jt = it -> prev;

        while (jt != NULL  && (jt -> no) > key){
            jt->next->no = jt->no;
            previous = jt;
            jt = jt->prev;
        }

        if (jt != NULL)     jt -> next -> no = key;
        else                previous -> no = key;
    }

    it = head;

    while (it != NULL){
        printf("no = %d\n", it->no);
        it = it->next;
    }

    return 0;
}
