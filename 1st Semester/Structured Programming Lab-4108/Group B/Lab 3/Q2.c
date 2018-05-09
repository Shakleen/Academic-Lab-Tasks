#include <stdio.h>

int main(){
    float a, b;
    char ch;
    printf("Enter 2 values:");
    scanf("%f %f", &a, &b);
    printf("Enter which operation you want to perform:");
    scanf(" %c", &ch);

    if (ch=='+')
        printf("%f+%f=%f", a, b, a+b);
    else if (ch =='-'){
        printf("%f-%f=%f\n", a, b, a-b);
        printf("%f-%f=%f", b, a, b-a);
    }
    else if (ch == '/'){
        printf("%f/%f=%f\n", a, b, a/b);
        printf("%f/%f=%f", b, a, b/a);
    }
    else if (ch == '*')
        printf("%fX%f=%f", a, b, a*b);
    else
        printf("Invalid command!");
    return 0;
}
