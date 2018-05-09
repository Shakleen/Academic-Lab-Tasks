#include <stdio.h>
#include <ctype.h>

int main(){
    char ch=0, v=0, c=0;

    while (ch!='0'){
        scanf("%c", &ch);
        ch=toupper(ch);
        if (ch=='A' || ch=='E' || ch=='O' || ch=='I' || ch=='U')
            v++;
        else if (ch>65 && ch<=90)
            c++;
    }
    printf("\nNo of vowels entered: %d", v);
    printf("\nNo of consonants entered: %d", c);

    return 0;
}
