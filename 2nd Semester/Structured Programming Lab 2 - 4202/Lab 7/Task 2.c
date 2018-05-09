#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct num{
    int no;
    struct num* next;
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
        }
        else{
            previous -> next = cur;
            cur -> next = NULL;
            previous = cur;
        }
    }

    printf("Enter K\n");

    scanf("%d", &k);

    for (i = 1; i <= k; i++){
        it = head;
        int key = previous->no, key2 = 0;

        while (it != NULL){
            key2 = it->no;
            it->no = key;
            it = it->next;

            if (it != NULL){
                key = key2;
            }
        }
    }

    it = head;

    while (it != NULL){
        printf("%d ", it->no);
        it = it->next;
    }

    return 0;
}
