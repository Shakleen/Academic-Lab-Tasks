#include <stdio.h>
#include <string.h>

int main(){
    char str[1000]={0};
    printf("\nEnter a string:\n");
    scanf("%s", &str);

    int i=0, n=strlen(str)-1, flag=0;
    for (i=0; i<=n/2; i++){
        if (str[i]!=str[n-i]){
            flag=1;
            break;
        }
    }
    if (flag)
        printf("NOT PALINDROME");
    else
        printf("PALINDROME");
    return 0;
}
