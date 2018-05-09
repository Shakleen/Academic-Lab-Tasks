#include <stdio.h>

int main(){
    int n=1, i=2;
    start:
    printf("\nEnter a positive number:");
    scanf("%d", &n);

    for (i=2; i<n; i++){
        if (n%i!=0)
            continue;
        else{
            printf("Number is not a prime!");
            goto start;;
            }
    }
    printf("Entered number is a prime!");

    return 0;
}
