#include <stdio.h>

int main(){
    int a=0, b=0, i=0;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    //For Odd Numbers
    printf("Odd Numbers between 1 and %d:", a);
    for (i=1; i<=a; i+=2)
        printf(" %d", i);
    //For Even numbers
    printf("\nEven Numbers between %d and %d:", a, b);
    for (i=a; i<=b; i++)
        if (i%2==0)
        printf(" %d", i);

    return 0;
}
