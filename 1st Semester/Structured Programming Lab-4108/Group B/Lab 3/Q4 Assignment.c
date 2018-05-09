#include <stdio.h>

int main(){
    char ch1=0, ch2=0;
    printf("Enter Hexadecimal value:\n");
    scanf("%c %c", &ch1, &ch2);

    if (ch1>='0' && ch1<='9')
        ch1=ch1-48;
    else
        ch1=ch1-55;

    if (ch2>='0' && ch2<='9')
        ch2=ch2-48;
    else
        ch2=ch2-55;

    printf("The converted Decimal value:%d", ch1*16+ch2);

    return 0;
}
