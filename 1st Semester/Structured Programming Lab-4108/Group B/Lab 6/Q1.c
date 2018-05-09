#include <stdio.h>

int main(){
    int x=0, i=0, j=1, k=0;
    printf("Please enter the size of the diamond:\n");
    scanf("%d", &x);

    for (i=1; i<=2*x-1; i++){
        if (i<=x){
            for (j=1; j<=(x-i+1); j++)
                printf("*");

            for (j=0; j<=(2*i-1); j++)
                printf(" ");

            for (j=1; j<=(x-i+1); j++)
                printf("*");

            printf("\n");
        }
        else{
            for (j=1; j<=(i-x+1); j++)
                printf("*");
            j=2*x-i;    k=2*j;
            for (j=1; j<=k; j++)
                printf(" ");

            for (j=1; j<=(i-x+1); j++)
                printf("*");

            printf("\n");
        }
    }
    return 0;
}
