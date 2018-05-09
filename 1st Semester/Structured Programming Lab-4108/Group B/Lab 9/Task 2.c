#include <stdio.h>

#define size 1000
void charinput(char ch[]);
int n;
char chr[size];
int main(){
    int s,i=0;
    printf("Please input the size of the character array:\n");
    scanf("%d", &s);
    n=s;
    charinput(chr);
    for (i=s-1; i>=0; i--){
        printf("%c \n", chr[i]);
    }
    return 0;
}
void charinput(char ch[]){
    n--;
    if (n>=0){
        scanf(" %c", &ch[n]);
        charinput(ch);
    }
}
