#include <stdio.h>

int main(){
    int a, b;
    printf("Enter a 3 digit integer number: ");
    scanf("%d", &a);

    printf("%d", a/100);
    b=a%100;
    printf("\n%d", b/10);
    printf("\n%d", b%10);
    return 0;
}
