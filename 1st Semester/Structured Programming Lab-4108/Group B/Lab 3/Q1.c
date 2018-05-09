#include <stdio.h>

int main(){
    int val1, val2;
    printf("Enter 2 values:");
    scanf("%d %d", &val1, &val2);

    if (val1%7==0)
        printf("%d can be divided by 7\n", val1);
    else
        printf("%d can't be divided by 7\n", val1);

    if (val2%11==0)
        printf("%d can be divided by 11\n", val2);
    else
        printf("%d can't be divided by 11\n", val2);

    return 0;
}
